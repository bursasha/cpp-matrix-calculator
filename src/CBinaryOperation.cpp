#include "CBinaryOperation.h"
#include "CException.h"
#include "CMessage.h"

shared_ptr<CMatrix> CBinaryOperation::sum (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	if (lhs_m->getRows () != rhs_m->getRows () || lhs_m->getColumns () != rhs_m->getColumns ())
		throw CException (CExceptionMessage ["BAD_DIMENSIONS"]);

	vector<double> result_elements;
	size_t result_rows = lhs_m->getRows (), result_columns = lhs_m->getColumns ();

	for (size_t row_idx = 0; row_idx < result_rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = lhs_m->getElement (row_idx, column_idx) + rhs_m->getElement (row_idx, column_idx);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::subtraction (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	if (lhs_m->getRows () != rhs_m->getRows () || lhs_m->getColumns () != rhs_m->getColumns ())
		throw CException (CExceptionMessage ["BAD_DIMENSIONS"]);

	vector<double> result_elements;
	size_t result_rows = lhs_m->getRows (), result_columns = lhs_m->getColumns ();
	
	for (size_t row_idx = 0; row_idx < result_rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = lhs_m->getElement (row_idx, column_idx) - rhs_m->getElement (row_idx, column_idx);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::product (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	if (lhs_m->getColumns () != rhs_m->getRows ()) throw CException (CExceptionMessage ["BAD_DIMENSIONS"]);

	vector<double> result_elements;
	size_t result_rows = lhs_m->getRows (), result_columns = rhs_m->getColumns (), products_count = lhs_m->getColumns ();
	
	for (size_t row_idx = 0; row_idx < result_rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = 0;

			for (size_t k = 0; k < products_count; k++)
				result_element += (lhs_m->getElement (row_idx, k) * rhs_m->getElement (k, column_idx));

			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::productConstant (const shared_ptr<CMatrix> m, const double factor)
{
	vector<double> result_elements;
	size_t result_rows = m->getRows (), result_columns = m->getColumns ();
	
	for (size_t row_idx = 0; row_idx < result_rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = m->getElement (row_idx, column_idx) * factor;
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::joinHorizontally (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	if (lhs_m->getRows () != rhs_m->getRows ()) throw CException (CExceptionMessage ["BAD_DIMENSIONS"]);

	vector<double> result_elements;
	size_t result_rows = lhs_m->getRows (), result_columns = (lhs_m->getColumns () + rhs_m->getColumns ());

	for (size_t row_idx = 0; row_idx < result_rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < lhs_m->getColumns (); column_idx++)
		{
			double result_element = lhs_m->getElement (row_idx, column_idx);
			result_elements.push_back (result_element);
		}

		for (size_t column_idx = 0; column_idx < rhs_m->getColumns (); column_idx++)
		{
			double result_element = rhs_m->getElement (row_idx, column_idx);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::joinVertically (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	if (lhs_m->getColumns () != rhs_m->getColumns ()) throw CException (CExceptionMessage ["BAD_DIMENSIONS"]);

	vector<double> result_elements;
	size_t result_rows = (lhs_m->getRows () + rhs_m->getRows ()), result_columns = lhs_m->getColumns ();

	for (size_t row_idx = 0; row_idx < lhs_m->getRows (); row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = lhs_m->getElement(row_idx, column_idx);
			result_elements.push_back(result_element);
		}
	}

	for (size_t row_idx = 0; row_idx < rhs_m->getRows (); row_idx++)
	{
		for (size_t column_idx = 0; column_idx < result_columns; column_idx++)
		{
			double result_element = rhs_m->getElement(row_idx, column_idx);
			result_elements.push_back(result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);

	return result_matrix;
}
