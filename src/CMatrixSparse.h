#ifndef MATRIXCALCULATOR_CMATRIXSPARSE_H
#define MATRIXCALCULATOR_CMATRIXSPARSE_H

#include "CMatrix.h"

/**
 * @brief
 * A class representing a sparse matrix.
 * */
class CMatrixSparse : public CMatrix
{
public:
	  /**
	  * @brief
	  * A basic sparse matrix constructor.
	  * @param rows - a number of rows in the matrix being initialized.
	  * @param columns - a number of columns in the matrix being initialized.
	  * @param determinant_sign - a determinant sign of matrix being initialized.
	  * @param input_elements - all the elements of the matrix being initialized.
	  * */
	 CMatrixSparse (const size_t rows, const size_t columns, const vector<double>& input_elements, const bool determinant_sign);

	 /**
	  * @brief
	  * A virtual function for getting the desired element.
	  * @param row_pos - a row index of the desired element.
	  * @param column_pos - a column index of the desired element.
	  * @return the element due to its linear index.
	  * */
	 double getElement (const size_t row_idx, const size_t column_idx) const override;

	 /**
	  * @brief
	  * A virtual function that outputs a sparse matrix to the console.
	  * */
	 void print () const override;

	 /**
	  * @brief
	  * A virtual function that saves a sparse matrix to a file with its name.
	  * @param name - optional argument for saving the matrix to a file. If it isn't saved as a variable in the calculator,
	  * but the user wants to output it to a file, then it will be called Result.txt, otherwise it will be called the matrix name + .txt
	  * @throw CException if can not open the file for saving. Uses message from CMessage.h
	  * */
	 void save (const char name = '\0') const override;

private:
	 /**
	  * @brief
	  * A data structure for efficient storage of non-zero elements of a sparse matrix.
	  * The key is the linear index of the element, the value is the element itself.
	  * */
	 map<size_t, double> m_SparseElements;

	 /**
	  * @brief
	  * A constant token containing the type of this matrix is used to write to the console and to a file.
	  * */
	 static constexpr const char * m_SparseToken = "Sparse";

};

#endif // MATRIXCALCULATOR_CMATRIXSPARSE_H
