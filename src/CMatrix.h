#ifndef MATRIXCALCULATOR_CMATRIX_H
#define MATRIXCALCULATOR_CMATRIX_H

#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief
 * A general abstract class representing an interface for a sparse and a dense matrix.
 */
class CMatrix
{
public:
	/**
	 * @brief
	 * A basic matrix constructor.
	 * @param rows - a number of rows in the matrix being initialized.
	 * @param columns - a number of columns in the matrix being initialized.
	 * @param determinant_sign - a determinant sign of matrix being initialized.
	 * */
	CMatrix (const size_t rows, const size_t columns, const bool determinant_sign)
	: m_Rows (rows), m_Columns (columns), m_Elements (rows * columns), m_DeterminantSign (determinant_sign) { }

	 virtual ~CMatrix () = default;

	 /**
	  * @brief
	  * A function that creates a sparse or dense matrix based on the number of zero elements.
	  * If the percentage of non-zero elements is less than or equal to 30%,
	  * then the function returns a sparse matrix, otherwise it returns a dense matrix.
	  * With determinant sign setting up. Is used for determinant calculation.
	  * @param rows - a number of rows in the matrix being created.
	  * @param columns - a number of columns in the matrix being created.
	  * @param input_elements - a vector containing all the elements of the matrix being created.
	  * @param determinant_sign - a determinant sign of matrix being created. A default value is true (is positive).
	  * @return a dense or a sparse matrix.
	  * */
	 static shared_ptr<CMatrix> createMatrix (const size_t rows, const size_t columns,
											  const vector<double>& input_elements, const bool determinant_sign = true);

	 /**
	  * @brief
	  * A virtual function that returns an element of the matrix.
	  * @param row_idx - a row index of the desired element.
	  * @param column_idx - a column index of the desired element.
	  * @return desired element of the matrix.
	  * */
	 virtual double getElement (const size_t row_idx, const size_t column_idx) const = 0;

	 /**
	  * @brief
	  * A getter that returns a number of rows in the matrix.
	  * */
	 size_t getRows () const { return m_Rows; }

	 /**
	 * @brief
	 * A getter that returns a number of columns in the matrix.
	 * */
	 size_t getColumns () const { return m_Columns; }

	  /**
	  * @brief
	  * A getter that returns a sign of a determinant of the matrix for finding the determinant itself.
	  * */
	 bool getDeterminantSign () const { return m_DeterminantSign; }

	 /**
	  * @brief
	  * A virtual function that outputs a matrix to the console depending on the type of matrix.
	  * */
	 virtual void print () const = 0;

	 /**
	  * @brief
	  * A virtual function that saves a matrix to a file with its name depending on its type.
	  * @param name - optional argument for saving the matrix to a file. If it isn't saved as a variable in the calculator,
	  * but the user wants to output it to a file, then it will be called Result.txt, otherwise it will be called the matrix name + .txt
	  * */
	 virtual void save (const char name = '\0') const = 0;

	 /**
	  * @brief
	  * A function for comparing 2 numbers of the double type.
	  * @param x - the first double number.
	  * @param y - the second double number.
	  * @return true, if two numbers are close enough taking into account the inaccuracy, false otherwise.
	  * */
	 static bool closeEnough (const double x, const double y) { return fabs (x - y) < m_Inaccuracy; }

protected:
	 /**
	  * @brief
	  * A number of rows, columns, and elements in the matrix.
	  * */
	 size_t m_Rows, m_Columns, m_Elements;

	 /**
	  * @brief
	  * A determinant sign of the matrix, true = +, false = -. A default value is true.
	  * */
	 bool m_DeterminantSign;

	 /**
	  * @brief
	  * The inaccuracy error of comparing 2 double numbers;
	  * the limit of the content of non-zero elements to create a sparse or dense matrix.
	  * */
	 static constexpr const double m_Inaccuracy = 1e-9, m_DensityBoundary = 0.3;

	/**
	 * @brief
	 * Variable for the field width of the output element;
	 * variable for the accuracy of the output element.
	 * */
	 static constexpr const size_t m_ElementWidth = 13, m_ElementPrecision = 7;

	 /**
	  * @brief
	  * A function that determines the percentage of non-zero elements in the matrix.
	  * @param rows - a number of rows in the considered matrix.
	  * @param columns - a number of columns in the considered matrix.
	  * @param input_elements - all the elements of the considered matrix.
	  * @return density of the matrix.
	  * */
	 static double getDensity (const size_t rows, const size_t columns, const vector<double>& input_elements);

};

#endif // MATRIXCALCULATOR_CMATRIX_H
