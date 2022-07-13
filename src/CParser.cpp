#include "CParser.h"
#include "CMatrix.h"
#include "CException.h"
#include "CMessage.h"

size_t CParser::parseOption ()
{
	 size_t option;
	 while (true)
	 {
		  cin >> option;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good () && (option == m_OptionOne || option == m_OptionTwo)) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_OPTION"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return option;
}

char CParser::parseName ()
{
	char name;
	while (true)
	{
		cin >> name;
		if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		if (cin.good () && isupper (name)) break;
		cin.clear ();
		cin.ignore (numeric_limits<streamsize>::max(), '\n');
		cerr << CErrorMessage ["BAD_NAME"] << endl;
	}
	cin.ignore (numeric_limits<streamsize>::max(), '\n');
	cout << endl;

	return name;
}

pair<int, int> CParser::parseDimensions ()
{
	int rows, columns;
	while (true)
	{
		cin >> rows >> columns;
		if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		if (cin.good () && rows > m_DimensionBoundary && columns > m_DimensionBoundary) break;
		cin.clear ();
		cin.ignore (numeric_limits<streamsize>::max(), '\n');
		cerr << CErrorMessage ["BAD_DIMENSIONS"] << endl;
	}
	cin.ignore (numeric_limits<streamsize>::max(), '\n');
	cout << endl;

	return make_pair (rows, columns);
}

pair<int, int> CParser::parseIndexes ()
{
	 int row_idx, column_idx;
	 while (true)
	 {
		  cin >> row_idx >> column_idx;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good () && row_idx >= m_IndexBoundary && column_idx >= m_IndexBoundary) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_INDEXES"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return make_pair (row_idx, column_idx);
}

string CParser::parseOperation ()
{
	 string operation;
	 while (true)
	 {
		  cin >> operation;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good ()) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_OPERATION"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return operation;
}

double CParser::parseConstant ()
{
	 double constant;
	 while (true)
	 {
		  cin >> constant;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good () && !CMatrix::closeEnough (constant, 0)) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_CONSTANT"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return constant;
}

vector<double> CParser::parseElements (const int rows, const int columns)
{
	 vector<double> elements;
	 for (int i = 0; i < (rows * columns); )
	 {
		  double element;
		  cin >> element;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good ())
		  {
				elements.push_back (element);
				i++;
				continue;
		  }
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_ELEMENT"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return elements;
}

pair<pair<int, int>, vector<double>> CParser::parseFile ()
{
	 cout << CUIMessage ["ENTER_PATH"] << endl;
	 string file_name;
	 while (true)
	 {
		  cin >> file_name;
		  if (cin.eof ()) throw CException (CExceptionMessage ["EOF"]);
		  if (cin.good ()) break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << CErrorMessage ["BAD_FILENAME"] << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');

	 ifstream ifs (file_name);
	 if (ifs.fail () || !(ifs.is_open ()))
	 {
		  ifs.close ();
		  throw CException (CExceptionMessage ["BAD_FILE"]);
	 }

	 string token;
	 int rows, columns;
	 char symbol_1, symbol_2, symbol_3, symbol_4;
	 if (!(ifs >> token >> symbol_1 >> rows >> symbol_2 >> columns >> symbol_3 >> symbol_4) ||
	 	 (token != m_SparseToken && token != m_DenseToken) || symbol_1 != m_LeftRoundBrace || rows <= m_DimensionBoundary ||
		  symbol_2 != m_Comma || columns <= m_DimensionBoundary || symbol_3 != m_RightRoundBrace || symbol_4 != m_Colon)
	 {
		  ifs.close ();
		  throw CException (CExceptionMessage ["BAD_FORMATTING"]);
	 }

	 size_t dimensions = rows * columns;
	 double element;
	 vector<double> elements (dimensions, 0);
	 if (token == m_DenseToken)
	 {
		  for (size_t i = 0; i < dimensions; i++)
		  {
		 	   if (!(ifs >> element))
		 	   {
		 			ifs.close ();
		 			throw CException (CExceptionMessage ["BAD_FORMATTING"]);
		 	   }
		 	   elements [i] = element;
		  }
	 }
	 else if (token == m_SparseToken)
	 {
		  char symbol_1, symbol_2, symbol_3, symbol_4;
		  int row_idx, column_idx;
		  while (ifs >> symbol_1 >> row_idx >> symbol_2 >> column_idx >> symbol_3 >> symbol_4)
		  {
			   if (symbol_1 != m_LeftSquareBrace || row_idx < m_IndexBoundary || row_idx >= rows || symbol_2 != m_Comma ||
			       column_idx < m_IndexBoundary || column_idx >= columns || symbol_3 != m_RightSquareBrace || symbol_4 != m_Equal || !(ifs >> element))
			   {
				   ifs.close ();
				   throw CException (CExceptionMessage ["BAD_FORMATTING"]);
			   }
			   size_t index = ((row_idx * columns) + column_idx);
			   elements [index] = element;
		  }
	 }
	 ifs.close ();

	 return make_pair (make_pair (rows, columns), elements);
}
