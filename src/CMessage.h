#ifndef MATRIXCALCULATOR_CMESSAGE_H
#define MATRIXCALCULATOR_CMESSAGE_H

#include <string>
#include <unordered_map>
using namespace std;

/**
 * @brief
 * A data structure for storing messages of exceptions that occur during the operation of the calculator.
 * */
static unordered_map<string, string> CExceptionMessage =
{
		{"BAD_DIMENSIONS", "The matrices are not of suitable dimensions."},
		{"NOT_SQUARE", "The number of rows does not correspond to the number of columns, it is not square."},
		{"NOT_REVERSIBLE", "The determinant of the matrix is 0, the matrix is irreversible."},
		{"BAD_INDEXES", "The entered indexes go beyond the matrix dimensions."},
		{"BAD_FILE", "The exception occurred when opening the file."},
		{"BAD_FORMATTING", "The opened file for reading the matrix is incorrectly formatted."},
		{"EOF", "The program was interrupted by the completion of the input."}
};

/**
 * @brief
 * A data structure for storing messages of errors that occur during the operation of the calculator.
 * */
static unordered_map<string, string> CErrorMessage =
{
		{"BAD_OPTION", "Invalid input of option, try again."},
		{"BAD_NAME", "Invalid input of name, try again."},
		{"BAD_DIMENSIONS", "Invalid input of dimensions, try again."},
		{"BAD_INDEXES", "Invalid input of indexes, try again."},
		{"BAD_OPERATION", "Invalid input of operation, try again."},
		{"BAD_CONSTANT", "Invalid input of constant, try again."},
		{"BAD_ELEMENT", "Invalid input of element, try again."},
		{"BAD_FILENAME", "Invalid input of file name, try again."},
		{"BAD_LOG", "The ExceptionLog.txt can't be opened to record an exception."},
};

/**
 * @brief\
 * Data structure for storing calculator user interface messages.
 * */
static unordered_map<string, string> CUIMessage =
{
		{"INVITATION", "You have launched the matrix calculator.\n\n"
				       "First, fill in 1 matrix which you will be able to work with later.\n"
					   "If you want to test a loading of matrix, try it from examples/ folder.\n\n"
		               "Then there will be available different calculator operations.\n\n"
					   "If you want to load a matrix from a file, it should be formatted as are formatted\n"
		               "example files in examples/ folder, there are 2 types of matrices and 2 types\n"
					   "of their print and save operation.\n\n"
					   "The recommendation is to read the message on the HELP command, there you will get\n"
					   "acquainted with all possible exceptions when working with the calculator and not only."},
		{"SET_LOG", "Select if you want to write an exception that occurs to a file ExceptionLog.txt:\n1 = file\n2 = console"},
		{"SET_UP", "The log destination was successfully set up."},
		{"DELIMITER", "*************************************************************************************************"},
		{"MENU", "Available operations:\n"
		         "-----------------------------------------------------------------------------------------------\n"
				 "NEW (Add/modify) | PRINT (Print to the console) | SAVE (Save to a file) | DEL (Delete a matrix)\n"
				 "-----------------------------------------------------------------------------------------------\n"
				 "        PRD_C (Product with a constant) | TRAN (Transpose) | GEM (Gaussian elimination)\n"
				 "-----------------------------------------------------------------------------------------------\n"
				 "         INV (Inverse) | TRIM | SUM | SUB (Subtraction) | PRD_M (Product of matrices)\n"
				 "-----------------------------------------------------------------------------------------------\n"
				 "    JOIN_H (Join horizontally) | JOIN_V (Join vertically) | DET (Determinant) | HELP | EXIT\n"
				 "-----------------------------------------------------------------------------------------------"},
		{"HELP", "This calculator is capable of performing various unary and binary operations with the\n"
				 "entered matrices. The loaded matrices are saved in the calculator's matrix list and then\n"
				 "the possibility of operations with them is provided.\n\n"
				 "The matrix can be loaded with a name presented as one capital letter of the English alphabet.\n\n"
				 "The calculator stops its work after entering the EXIT command or with 7 possible exceptions:\n"
				 "- with different dimensions of the operated matrices;\n"
				 "- when using a non-square matrix to calculate the determinant or inversion;\n"
				 "- when detecting an irreversible matrix when searching for the inverse matrix;\n"
				 "- when entering invalid element indexes into the console or reading from a file to add an element\n"
				 "or trimming the matrix;\n"
				 "- when the file with loaded matrix is incorrectly formatted;\n"
				 "- if it is impossible to open the file to load the matrix or for writing exception;\n"
				 "- when the input is finished (EOF).\n\n"
				 "The file for loading the matrix from it must be formatted correctly, in the examples/ folder\n"
				 "there are several examples of the correct formatting of a dense and sparse matrix."},
		{"ENTER_OPERATION", "Enter the type of operation:"},
		{"NO_MATRICES", "There is not any matrix available for operations."},
		{"AVAILABLE_MATRICES", "Available matrices for operations: "},
		{"LOAD_OR_ENTER", "Select if you want to load the matrix from a file or enter it to the console:\n1 = file\n2 = console"},
		{"ENTER_NAME", "Enter the name of the matrix (capital letter of the English alphabet):"},
		{"ENTER_DIMENSIONS", "Enter the dimensions (number of rows and columns):"},
		{"ENTER_INDEXES", "Enter the row and the column indexes from which the matrix will be trimmed:"},
		{"ENTER_ELEMENTS", "Enter the elements of the matrix:"},
		{"ENTER_PATH", "Enter the path of file with matrix:"},
		{"UPLOADED", " matrix was successfully uploaded."},
		{"SAVING", "The matrix is saving to "},
		{"SAVED", " matrix was successfully saved."},
		{"DELETED", " matrix was successfully deleted."},
		{"SAVE_NEW_OR_NO", "Select if you want to save the result as a new matrix:\n1 = yes\n2 = no"},
		{"SAVE_OR_PRINT", "Select if you want to save the result to a file or print it to the console:\n1 = file\n2 = console"},
		{"EXIT", "You exit the calculator."},
		{"BAD_OPERATION", "You have entered an invalid operation."},
		{"ENTER_ONE_OPERAND", "Enter the name of the operated matrix:"},
		{"ENTER_LHS_OPERAND", "Enter the name of the left-hand side matrix:"},
		{"ENTER_RHS_OPERAND", "Enter the name of the right-hand side matrix:"}
};


#endif // MATRIXCALCULATOR_CMESSAGE_H
