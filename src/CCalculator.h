#ifndef MATRIXCALCULATOR_CCALCULATOR_H
#define MATRIXCALCULATOR_CCALCULATOR_H

#include "CMatrix.h"

/**
 * @brief
 * The class responsible for performing all input, write, and matrix operations.
 * Uses messages for the calculator user interface from a file CMessage.h
 * Available menu operations:
 * NEW (Add/modify), PRINT (Print to the console), SAVE (Save to a file), DEL (Delete a matrix), PRD_C (Product with a constant),
 * TRAN (Transpose), GEM (Gaussian elimination), INV (Inverse), TRIM, SUM, SUB (Subtraction), PRD_M (Product of matrices),
 * JOIN_H (Join horizontally), JOIN_V (Join vertically), DET (Determinant), HELP, EXIT.
 * */
class CCalculator
{
public:

	 CCalculator ()
	 : m_Matrices (), m_LogDestination () { }

	 /**
	  * @brief
	  * A function that launches the calculator, its menu with all operations inside.
	  * */
	 void run ();

private:
	 /**
	  * @brief
	  * A data structure for storing matrices with their names written in the form of a capital letter of the English alphabet.
	  * */
	 map<char, shared_ptr<CMatrix>> m_Matrices;

	 /**
	  * @brief
	  * Determines the recording location of the error that occurs during the operation of the calculator.
	  * True = to the ExceptionLog.txt, false = to the console.
	  * */
	 bool m_LogDestination;

	 /**
	  * @brief
	  * 2 possible selection options in the calculator menu. There are only 2 options available to choose from, 1 and 2.
	  * */
	 static constexpr const size_t m_OptionOne = 1, m_OptionTwo = 2;

	 /**
	  * @brief
	  * Setting up the recording of an error that occurs to a file or to the console.
	  * */
	 void setLogDestination ();

	 /**
	  * @brief
	  * Writes out all the matrices stored in the calculator along with their names and their dimensions ready for operations.
	  * */
	 void availableMatrices ();

	 /**
	  * @brief
	  * Improved matrix name parser with checking for the presence of a matrix in the calculator matrix list.
	  * @return the name of the matrix from the calculator list for subsequent work with it.
	  * */
	 char getOperand ();

	 /**
	  * @brief
	  * A function for obtaining a matrix for performing an unary or binary operation with it.
	  * @return a name of the matrix being operated.
	  * */
	 char oneOperand ();

	 /**
	  * @brief
	  * A function for obtaining a matrix for performing a binary operation with them.
	  * @return names of the matrices being operated.
	  * */
	 pair<char, char> twoOperands ();

	 /**
	  * @brief
	  * Operation NEW.
	  * A function that provides a choice of downloading from a prepared file with the correct formatting or
	  * entering it from the console. This matrix will be saved in the calculator matrix list.
	  * */
	 void operateNew ();

	 /**
	  * @brief
	  * Operations PRD_C (product with a constant), TRAN (transpose), GEM (Gaussian elimination), INV (inverse), TRIM.
	  * Template function for the above operations. The function requests to enter one matrix from the list of
	  * calculator matrices, performs the entered operation with it, then provides the ability to save the result to
	  * a new matrix or output it to the console or to a file.
	  * @param operation - the entered operation.
	  * */
	 void operateMatrix (const string operation);

	/**
	 * @brief
	 * Operations SUM, SUB (subtraction of matrices), PRD_M (product of matrices), JOIN_H (horizontally), JOIN_V (vertically).
	 * Template function for the above operations. The function requests to enter two matrix (the left-sided matrix and
	 * a right-sided matrix, they can be a one single matrix) from the list of calculator matrices,
	 * performs the entered operation with it, then provides the ability to save the result to a new matrix or
	 * output it to the console or to a file.
	 * @param operation - the entered operation.
	 * */
	 void operateMatrices (const string operation);

	 /**
	  * @brief
	  * Operations DET (determinant), PRINT (to the console), SAVE (in a file), DEL (delete from the calculator list).
	  * Template function for the above operations. Requests the name of the operated matrix, then calculates its
	  * determinant or outputs this matrix to the console or saves it to a file or deletes it from the calculator list.
	  * @param operation - the entered operation.
	  * */
	 void operateOther (const string operation);

};

#endif // MATRIXCALCULATOR_CCALCULATOR_H
