#include "CMatrixSparse.h"
#include "CException.h"
#include "CMessage.h"

CMatrixSparse::CMatrixSparse (const size_t rows, const size_t columns, const vector<double>& input_elements, const bool determinant_sign)
: CMatrix (rows, columns, determinant_sign)
{
	for (size_t row_idx = 0; row_idx < m_Rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < m_Columns; column_idx++)
		{
			size_t index = ((row_idx * m_Columns) + column_idx);
			double input_element = input_elements[index];
			if (!CMatrix::closeEnough (input_element, 0))
				 m_SparseElements.insert (make_pair (index, input_element));
		}
	}
}

double CMatrixSparse::getElement (const size_t row_idx, const size_t column_idx) const
{
	 size_t index = ((row_idx * m_Columns) + column_idx);
	 auto get_element = m_SparseElements.find (index);
	 return (get_element != m_SparseElements.end()) ? get_element->second : 0;
}

void CMatrixSparse::print () const
{
	 cout << m_SparseToken << " " << "(" << m_Rows << "," << m_Columns << "):" << endl;
	 if (m_SparseElements.empty ()) cout << endl;
	 else
	 {
		  for (const auto &idx_element: m_SparseElements)
		  {
			   size_t column_idx = (idx_element.first % m_Columns), row_idx = ((idx_element.first - column_idx) / m_Columns);
			   cout << "[" << row_idx << "," << column_idx << "] = " << setprecision (m_ElementPrecision) << idx_element.second << endl;
		  }
	 }
}

void CMatrixSparse::save (const char name) const
{
	string file_name;
	(name) ? file_name += name : file_name += "Result";
	ofstream ofs (file_name += ".txt");

	if (!ofs.is_open ())
	{
		ofs.close ();
		throw CException (CExceptionMessage ["BAD_FILE"]);
	}
	else
	{
		cout << CUIMessage ["SAVING"] + file_name << endl;
		ofs << m_SparseToken << " " << "(" << m_Rows << "," << m_Columns << "):" << endl;
		if (!m_SparseElements.empty ())
		{
			for (const auto &idx_element: m_SparseElements)
			{
				size_t column_idx = (idx_element.first % m_Columns), row_idx = ((idx_element.first - column_idx) / m_Columns);
				ofs << "[" << row_idx << "," << column_idx << "] = " << setprecision (m_ElementPrecision) << idx_element.second << endl;
			}
		}
		ofs.close ();
	}
}
