#include "CMatrix.h"
#include "CMatrixDense.h"
#include "CMatrixSparse.h"

shared_ptr<CMatrix> CMatrix::createMatrix (const size_t rows, const size_t columns,
										   const vector<double>& input_elements, const bool determinant_sign)
{
	shared_ptr<CMatrix> matrix;
	double density = getDensity (rows, columns, input_elements);
	if (density > m_DensityBoundary)
		matrix = make_shared<CMatrixDense> (rows, columns, input_elements, determinant_sign);
	else
		matrix = make_shared<CMatrixSparse> (rows, columns, input_elements, determinant_sign);
	
	return matrix;
}

double CMatrix::getDensity (const size_t rows, const size_t columns, const vector<double>& input_elements)
{
	size_t all_elements = rows * columns, zero_elements = 0;
	for (auto &x : input_elements)
	{
		if (closeEnough (x, 0))
			zero_elements++;
	}
	double density = ((double)all_elements - (double)zero_elements) / (double)all_elements;

	return density;
}
