#include "CCalculator.h"
#include "CUnaryOperation.h"
#include "CBinaryOperation.h"
#include "CParser.h"
#include "CException.h"
#include "CMessage.h"

void CCalculator::run ()
{
	 try
	 {
		  cout << CUIMessage ["DELIMITER"] << endl;
		  cout << CUIMessage ["INVITATION"] << endl << endl;
		  cout << CUIMessage ["DELIMITER"] << endl;
		  setLogDestination ();
		  cout << CUIMessage ["DELIMITER"] << endl;
		  operateNew ();

		  string op;
		  while (op != "EXIT")
		  {
				cout << CUIMessage ["DELIMITER"] << endl;
				cout << CUIMessage ["MENU"] << endl << endl;
				availableMatrices ();
				cout << CUIMessage ["ENTER_OPERATION"] << endl;
				op = CParser::parseOperation ();

				if (op == "NEW") operateNew ();

				else if (op == "DET" || op == "PRINT" || op == "SAVE" || op == "DEL")
					 operateOther (op);

				else if (op == "PRD_C" || op == "TRAN" || op == "GEM" || op == "INV" || op == "TRIM")
					 operateMatrix (op);

				else if (op == "SUM" || op == "SUB" || op == "PRD_M" || op == "JOIN_H" || op == "JOIN_V")
					 operateMatrices (op);

				else if (op == "HELP") cout << CUIMessage ["HELP"] << endl << endl;

				else if (op == "EXIT") cout << CUIMessage ["EXIT"] << endl;

				else cout << CUIMessage ["BAD_OPERATION"] << endl;
		  }
	 }
	 catch (CException& e)
	 {
		  e.what (m_LogDestination);
	 }
}

void CCalculator::setLogDestination ()
{
	cout << CUIMessage ["SET_LOG"] << endl;
	size_t option = CParser::parseOption ();
	m_LogDestination = (option == 1) ? true : false;

	cout << CUIMessage ["SET_UP"] << endl;
}

void CCalculator::availableMatrices ()
{
	 if (m_Matrices.empty ()) cout << CUIMessage ["NO_MATRICES"];
	 else
	 {
		  cout << CUIMessage ["AVAILABLE_MATRICES"];
		  for (const auto& name_matrix: m_Matrices)
			   cout << name_matrix.first << "(" << name_matrix.second->getRows () << "," << name_matrix.second->getColumns () << ") ";
	 }

	 cout << endl << endl;
}

char CCalculator::getOperand ()
{
	 char name;
	 while (true)
	 {
		  cin >> name;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good () && isupper (name) && m_Matrices.count (name)) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_NAME"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return name;
}

char CCalculator::oneOperand ()
{
	cout << CUIMessage ["ENTER_ONE_OPERAND"] << endl;
	char operand = getOperand ();

	return operand;
}

pair<char, char> CCalculator::twoOperands ()
{
	cout << CUIMessage ["ENTER_LHS_OPERAND"] << endl;
	char lhs = getOperand ();
	cout << CUIMessage ["ENTER_RHS_OPERAND"] << endl;
	char rhs = getOperand ();

	return make_pair (lhs, rhs);
}

void CCalculator::operateNew ()
{
	  cout << CUIMessage ["LOAD_OR_ENTER"] << endl;
	  size_t option = CParser::parseOption (), new_rows = 0, new_columns = 0;
	  vector<double> new_elements;

	  if (option == m_OptionOne)
	  {
		    pair<pair<int, int>, vector<double>> new_matrix = CParser::parseFile ();
			new_rows = new_matrix.first.first, new_columns = new_matrix.first.second;
			new_elements = new_matrix.second;
			cout << endl;
	  }

	  else if (option == m_OptionTwo)
	  {
		    cout << CUIMessage ["ENTER_DIMENSIONS"] << endl;
			pair<int, int> new_dimensions = CParser::parseDimensions ();
			new_rows = new_dimensions.first, new_columns = new_dimensions.second;

			cout << CUIMessage ["ENTER_ELEMENTS"] << endl;
		    new_elements = CParser::parseElements (new_rows, new_columns);
	  }

	  cout << CUIMessage ["ENTER_NAME"] << endl;
	  char new_name = CParser::parseName ();
	  m_Matrices [new_name] = CMatrix::createMatrix (new_rows, new_columns, new_elements);

	  cout << new_name << CUIMessage ["UPLOADED"] << endl;
}

void CCalculator::operateMatrix (const string operation)
{
	 if (m_Matrices.empty ()) cout << CUIMessage ["NO_MATRICES"] << endl;
	 else
	 {
		  char m = oneOperand ();
		  shared_ptr<CMatrix> result_matrix;

		  if (operation == "PRD_C")
		  {
			   cout << "Enter a constant other than 0:" << endl;
			   double constant = CParser::parseConstant ();
			   result_matrix = CBinaryOperation::productConstant (m_Matrices [m], constant);
		  }
		  else if (operation == "TRAN")
			   result_matrix = CUnaryOperation::transpose (m_Matrices [m]);
		  else if (operation == "GEM")
			   result_matrix = CUnaryOperation::gaussianElimination (m_Matrices [m]);
		  else if (operation == "INV")
			   result_matrix = CUnaryOperation::inverse (m_Matrices [m]);
		  else if (operation == "TRIM")
		  {
			   cout << CUIMessage ["ENTER_INDEXES"] << endl;
			   pair<int, int> row_column = CParser::parseIndexes ();
			   result_matrix = CUnaryOperation::trim (m_Matrices [m], row_column.first, row_column.second);
		  }

		  cout << CUIMessage ["SAVE_NEW_OR_NO"] << endl;
		  size_t option = CParser::parseOption ();
		  if (option == m_OptionOne)
		  {
			   cout << CUIMessage ["ENTER_NAME"] << endl;
			   char result_name = CParser::parseName ();
			   m_Matrices [result_name] = result_matrix;
			   cout << result_name << CUIMessage ["UPLOADED"] << endl;
		  }

		  else if (option == m_OptionTwo)
		  {
			   cout << CUIMessage ["SAVE_OR_PRINT"] << endl;
			   option = CParser::parseOption ();
			   if (option == m_OptionOne)
			   {
				    result_matrix->save ();
					cout << "Result" << CUIMessage ["SAVED"] << endl;
			   }
			   else if (option == m_OptionTwo) result_matrix->print ();
		  }
	 }
}

void CCalculator::operateMatrices (const string operation)
{
	  if (m_Matrices.empty ()) cout << CUIMessage ["NO_MATRICES"] << endl;
	  else
	  {
		    pair<char, char> lhs_rhs = twoOperands ();
		    char lhs = lhs_rhs.first, rhs = lhs_rhs.second;
			shared_ptr<CMatrix> result_matrix;

			if (operation == "SUM")
				 result_matrix = CBinaryOperation::sum (m_Matrices [lhs], m_Matrices [rhs]);
			else if (operation == "SUB")
				 result_matrix = CBinaryOperation::subtraction (m_Matrices [lhs], m_Matrices [rhs]);
			else if (operation == "PRD_M")
				 result_matrix = CBinaryOperation::product (m_Matrices [lhs], m_Matrices [rhs]);
			else if (operation == "JOIN_H")
				 result_matrix = CBinaryOperation::joinHorizontally (m_Matrices [lhs], m_Matrices [rhs]);
			else if (operation == "JOIN_V")
				 result_matrix = CBinaryOperation::joinVertically (m_Matrices [lhs], m_Matrices [rhs]);

		    cout << CUIMessage ["SAVE_NEW_OR_NO"] << endl;
		    size_t option = CParser::parseOption ();
			if (option == m_OptionOne)
			{
				  cout << CUIMessage ["ENTER_NAME"] << endl;
				  char result_name = CParser::parseName ();
				  m_Matrices [result_name] = result_matrix;
				  cout << result_name << CUIMessage ["UPLOADED"] << endl;
			}

			else if (option == m_OptionTwo)
			{
				  cout << CUIMessage ["SAVE_OR_PRINT"] << endl;
				  option = CParser::parseOption ();
				  if (option == m_OptionOne)
				  {
					   result_matrix->save ();
					   cout << "Result" << CUIMessage ["SAVED"] << endl;
				  }
				  else if (option == m_OptionTwo) result_matrix->print ();
			}
	  }
}

void CCalculator::operateOther (const string operation)
{
	 if (m_Matrices.empty ()) cout << CUIMessage ["NO_MATRICES"] << endl;
	 else
	 {
		  char m = oneOperand ();

		  if (operation == "DET")
		  {
			   double determinant = CUnaryOperation::determinant (m_Matrices [m]);
			   cout << m << "(" << m_Matrices [m]->getRows () << "," << m_Matrices [m]->getColumns () << ") = " << determinant << endl;
		  }
		  else if (operation == "PRINT") m_Matrices [m]->print ();
		  else if (operation == "SAVE")
		  {
			   m_Matrices [m]->save (m);
			   cout << m << CUIMessage ["SAVED"] << endl;
		  }
		  else if (operation == "DEL")
		  {
			   m_Matrices.erase (m);
			   cout << m << CUIMessage ["DELETED"] << endl;
		  }
	 }
}
