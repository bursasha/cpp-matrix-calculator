#ifndef MATRIXCALCULATOR_CUNARYOPERATION_H
#define MATRIXCALCULATOR_CUNARYOPERATION_H

#include "CMatrix.h"

/**
 * @brief
 * A class containing static functions for performing unary operations on matrices.
 * Uses CMatrix::createMatrix function to return a dense or a sparse matrix as a result.
 * Uses CMatrix::closeEnough function for checking zero elements.
 * */
class CUnaryOperation
{
public:
	 /**
	  * @brief
	  * A function that returns a transposed matrix.
	  * @param m - a received matrix to be transposed.
	  * @return a new matrix that is transposed matrix m, the matrix m remains the same.
	  * */
	 static shared_ptr<CMatrix> transpose (const shared_ptr<CMatrix> m);

	 /**
	  * @brief
	  * A function that returns a matrix after Gaussian elimination process.
	  * Uses CMatrix::closeEnough function for checking 0 elements.
	  * @param m - a received matrix to be GEMed.
	  * @return a new matrix that is GEMed matrix m, the matrix m remains the same.
	  * */
	 static shared_ptr<CMatrix> gaussianElimination (const shared_ptr<CMatrix> m);

	 /**
	  * @brief
	  * A function that returns an inverse matrix.
	  * @param m - a received matrix to be inverted.
	  * @throw CException if the matrix is not square or is irreversible, its determinant is 0. Uses message from CMessage.h
	  * @return a new matrix that is inverted matrix m, the matrix m remains the same.
	  * */
	 static shared_ptr<CMatrix> inverse (const shared_ptr<CMatrix> m);

	 /**
	  * @brief
	  * A function that returns a determinant of the matrix.
	  * @param m - a received matrix for getting its determinant.
	  * @throw CException if the matrix is not square. Uses message from CMessage.h
	  * @return a determinant of the matrix m.
	  * */
	 static double determinant (const shared_ptr<CMatrix> m);

	 /**
	  * @brief
	  * A function that returns a trimmed matrix.
	  * @param m - a received matrix to be trimmed.
	  * @param row_idx - a row index starting from which the matrix m will be trimmed.
	  * @param column_idx - a column index starting from which the matrix m will be trimmed.
	  * @throw CException if received indexes go beyond the matrix dimensions. Uses message from CMessage.h
	  * @return a new matrix that is trimmed matrix m, the matrix m remains the same.
	  * */
	 static shared_ptr<CMatrix> trim (const shared_ptr<CMatrix> m, const size_t row_idx, const size_t column_idx);

private:
	 /**
	  * @brief
	  * Auxiliary function for Gaussian elimination,
	  * finds the index of the row with the largest element in a particular column of the matrix.
	  * @param matrix_elements - elements of the matrix on which this function will be performed.
	  * @param rows - a number of rows in the considered matrix.
	  * @param columns - a number of columns in the considered matrix.
	  * @param column_idx - a specific column of the matrix.
	  * @return an index of the row with the largest element.
	  * */
	 static size_t findMaxElementRowInColumn (const vector<double>& matrix_elements, const size_t rows,
														  const size_t columns, const size_t column_idx);

	 /**
	  * @brief
	  * Auxiliary function for Gaussian elimination which switches 2 rows of the matrix.
	  * @param matrix_elements - elements of the matrix on which this function will be performed.
	  * @param columns - a number of columns in the considered matrix.
	  * @param row_i - an index of one of 2 rows that we want to swap.
	  * @param row_j - an index of one of 2 rows that we want to swap.
	  * */
	 static void switchRows (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
									const size_t row_j);

	 /**
	  * @brief
	  * Auxiliary function for Gaussian elimination which multiplies a row of the matrix by the entered constant.
	  * @param matrix_elements - elements of the matrix on which this function will be performed.
	  * @param columns - a number of columns in the considered matrix.
	  * @param row_i - an index of the row which will be multiplied.
	  * @param factor - an entered constant.
	  * */
	 static void multiplyRow (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
									 const double factor);

	 /**
	  * @brief
	  * Auxiliary function for Gaussian elimination and inversion
	  * which adds a multiple of one row of the matrix to another row.
	  * @param matrix_elements - elements of the matrix on which this function will be performed.
	  * @param columns - a number of columns in the considered matrix.
	  * @param row_i - an index of the row to which another row multiple will be added.
	  * @param row_j - an index of the row which will be multiplied by the constant.
	  * @param factor - an entered constant.
	  * */
	 static void addRowMultiple (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
										 const size_t row_j, const double factor);

};

#endif // MATRIXCALCULATOR_CUNARYOPERATION_H
