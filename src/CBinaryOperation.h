#ifndef MATRIXCALCULATOR_CBINARYOPERATION_H
#define MATRIXCALCULATOR_CBINARYOPERATION_H

#include "CMatrix.h"

/**
 * @brief
 * A class containing static functions for performing binary operations on matrices.
 * Uses CMatrix::createMatrix function to return a dense or a sparse matrix as a result.
 * */
class CBinaryOperation
{
public:
	 /**
	  * @brief
	  * A function that returns a sum of 2 matrices. Receives 2 matrices with same dimensions.
	  * @param lhs_m - the first received matrix.
	  * @param rhs_m - the second received matrix.
	  * @throw CException if lhs and rhs matrices do not have the same dimensions. Uses message from CMessage.h
	  * @return a new matrix that is a sum of lhs_m and rhs_m.
	  * */
	 static shared_ptr<CMatrix> sum (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m);

	 /**
	  * @brief
	  * A function that performs the subtraction of 2 matrices. Receives 2 matrices with same dimensions.
	  * @param lhs_m - the first received matrix, the second matrix will be subtracted from it.
	  * @param rhs_m - the second received matrix.
	  * @throw CException if lhs and rhs matrices do not have the same dimensions. Uses message from CMessage.h
	  * @return a new matrix: lhs_m - rhs_m.
	  * */
	 static shared_ptr<CMatrix> subtraction (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m);

	 /**
	  * @brief
	  * A function that returns a product of 2 matrices.
	  * Receives 2 matrices where number of columns of the first matrix is same as number of rows of the second matrix.
	  * @param lhs_m - the first received matrix.
	  * @param rhs_m - the second received matrix.
	  * @throw CException if lhs columns are not the same as rhs rows. Uses message from CMessage.h
	  * @return a new matrix: lhs_m * rhs_m.
	  * */
	 static shared_ptr<CMatrix> product (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m);

	 /**
	  * @brief
	  * A function that returns a product of a matrix with a constant other than 0.
	  * @param m - a received matrix.
	  * @param factor - a received constant other than 0.
	  * @return a new matrix: lhs_m * factor.
	  * */
	 static shared_ptr<CMatrix> productConstant (const shared_ptr<CMatrix> m, const double factor);

	 /**
	  * @brief
	  * A function that returns a horizontally joined matrix. Receives 2 matrices with same number of rows.
	  * @param lhs_m - the first received matrix.
	  * @param rhs_m - the second received matrix.
	  * @throw CException if lhs rows are not the same as rhs rows. Uses message from CMessage.h
	  * @return a new matrix: lhs_m join rhs_m.
	  * */
	 static shared_ptr<CMatrix> joinHorizontally (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m);

	 /**
	  * @brief
	  * A function that returns a vertically joined matrix. Receives 2 matrices with same number of columns.
	  * @param lhs_m - the first received matrix.
	  * @param rhs_m - the second received matrix.
	  * @throw CException if lhs columns are not the same as rhs columns. Uses message from CMessage.h
	  * @return a new matrix:
	  * lhs_m
	  * join
	  * rhs_m.
	  * */
	 static shared_ptr<CMatrix> joinVertically (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m);

};

#endif // MATRIXCALCULATOR_CBINARYOPERATION_H
