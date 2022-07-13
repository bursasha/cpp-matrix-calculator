#ifndef MATRIXCALCULATOR_CMATRIXDENSE_H
#define MATRIXCALCULATOR_CMATRIXDENSE_H

#include "CMatrix.h"

/**
 * @brief
 * A class representing a dense matrix.
 * */
class CMatrixDense : public CMatrix
{
public:
	/**
	 * @brief
	 * A basic dense matrix constructor.
	 * @param rows - a number of rows in the matrix being initialized.
	 * @param columns - a number of columns in the matrix being initialized.
	 * @param determinant_sign - a determinant sign of matrix being initialized.
	 * @param input_elements - all the elements of the matrix being initialized.
	 * */
	 CMatrixDense (const size_t rows, const size_t columns, const vector<double>& input_elements, const bool determinant_sign)
	 : CMatrix (rows, columns, determinant_sign), m_DenseElements (input_elements) { }

	/**
	 * @brief
	 * A virtual function for getting the desired element.
	 * @param row_idx - a row index of the desired element.
	 * @param column_idx - a column index of the desired element.
	 * @return the element due to its linear index.
	 * */
	 double getElement (const size_t row_idx, const size_t column_idx) const override
	 { return m_DenseElements[(row_idx * m_Columns) + column_idx]; }

	/**
	  * @brief
	  * A virtual function that outputs a dense matrix to the console.
	  * */
	 void print () const override;

	/**
	 * @brief
	 * A virtual function that saves a dense matrix to a file with its name.
	 * @param name - optional argument for saving the matrix to a file. If it isn't saved as a variable in the calculator,
	  * but the user wants to output it to a file, then it will be called Result.txt, otherwise it will be called the matrix name + .txt
	 * @throw CException if can not open the file for saving. Uses message from CMessage.h
	 * */
	 void save (const char name = '\0') const override;

private:
	 /**
	  * @brief
	  * A data structure for efficient storage of non-zero elements of a dense matrix.
	  * */
	 vector<double> m_DenseElements;

	/**
	 * @brief
	 * A constant token containing the type of this matrix is used to write to the console and to a file.
	 * */
	 static constexpr const char * m_DenseToken = "Dense";

};

#endif // MATRIXCALCULATOR_CMATRIXDENSE_H
