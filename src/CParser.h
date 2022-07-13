#ifndef MATRIXCALCULATOR_CPARSER_H
#define MATRIXCALCULATOR_CPARSER_H

#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief
 * The class responsible for entering and processing the entered information
 * from the console and from the file.
 * */
class CParser
{
public:
	 /**
	  * @brief
	  * Reads from the console the number of the option requested in the calculator. It must be only of 2 types: 1 or 2.
	  * It is checked with m_OptionOne and m_OptionTwo.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return a number of the selected option in the menu for the subsequent processing of their correctness.
	  * */
	 static size_t parseOption ();

	 /**
	  * @brief
	  * Reads from the console a name of the matrix being created or the matrix selected for the operation. It must be an uppercase char.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return a name of matrix in the menu for the subsequent processing of its correctness.
	  * */
	 static char parseName ();

	 /**
	  * @brief
	  * Reads number of rows and columns of a matrix from the console to create a matrix. Dimensions must be greater than 0,
	  * it is checked with m_DimensionBoundary.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return pair of indexes for the subsequent processing of their correctness.
	  * */
	 static pair<int, int> parseDimensions ();

	 /**
	  * @brief
	  * Reads indexes of a matrix element from the console for different operations. Indexes must be >= than 0,
	  * it is checked with m_IndexBoundary.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return pair of indexes for the subsequent processing of their correctness.
	  * */
	 static pair<int, int> parseIndexes ();

	 /**
	  * @brief
	  * Reads the type of operation from the console for subsequent verification and execution.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return a string for subsequent verification of the correctness of the written operation.
	  * */
	 static string parseOperation ();

	 /**
	  * @brief
	  * Reads the multiplier constant for the matrix product operation by a number. It must be other than 0,
	  * it is checked with CMatrix::closeEnough function.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return the number that will be checked whether it is zero.
	  * */
	 static double parseConstant ();

	 /**
	  * @brief
	  * A function that accepts numbers of rows and columns of the matrix for the next parsing of its elements from the console.
	  * @param rows - a number of rows of the parsed matrix.
	  * @param columns - a number of columns of the parsed matrix.
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * @return vector of all parsed elements.
	  * */
	 static vector<double> parseElements (const int rows, const int columns);

	 /**
	  * @brief
	  * Reads the matrix from the file entered in the console. The file for reading can be of 2 types:
	  * with a dense matrix or with a sparse one. The file starts with a token, a matrix type.
	  * It is followed by its dimensions inside braces. After the colon, only all its elements are located in a dense matrix.
	  * In a sparse matrix, for efficient data storage, only the indexes of elements and their values are written,
	  * the indexes are written in square brackets, after which the equal sign and the element itself are written.
	  *
	  * A token can have only 2 values, 2 types of brackets are checked, a colon, a comma,
	  * the dimensions of the matrix must be greater than 0 (m_DimensionBoundary), indexes must be at least 0 (m_IndexBoundary),
	  * all this is checked inside the parser using private constant variables.
	  *
	  * @throw CException (CExceptionMessage ["EOF"]), if the end of the input has been reached. Uses CMessage.h file.
	  * CException (CExceptionMessage ["BAD_FILE"]), if the file for loading the matrix cannot be opened,
	  * CException (CExceptionMessage ["BAD_FORMATTING"]), if the file is not formatted as described above.
	  *
	  * @return big data structure where in the first pair are located matrix dimensions, and a vector with its elements.
	  * */
	 static pair<pair<int, int>, vector<double>> parseFile ();

private:
	 /**
	  * @brief
	  * Constant variables to check the correct formatting of the read files and the console input.
	  * */
	  static constexpr const char m_LeftRoundBrace = '(', m_RightRoundBrace = ')', m_Comma = ',', m_Colon = ':',
	                       m_LeftSquareBrace = '[', m_RightSquareBrace = ']', m_Equal = '=';
	  static constexpr const size_t m_OptionOne = 1, m_OptionTwo = 2;
	  static constexpr const int m_DimensionBoundary = 0, m_IndexBoundary = 0;
	  static constexpr const char* m_SparseToken = "Sparse";
	  static constexpr const char* m_DenseToken = "Dense";
};

#endif // MATRIXCALCULATOR_CPARSER_H
