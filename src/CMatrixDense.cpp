#include "CMatrixDense.h"
#include "CException.h"
#include "CMessage.h"

void CMatrixDense::print () const
{
	cout << m_DenseToken << " " << "(" << m_Rows << "," << m_Columns << "):" << endl;
	for (size_t row_idx = 0; row_idx < m_Rows; row_idx++)
	{
		for (size_t column_idx = 0; column_idx < m_Columns; column_idx++)
			cout << setw (m_ElementWidth) << setprecision (m_ElementPrecision)
				 << getElement (row_idx, column_idx) << " ";
		cout << endl;
	}
}

void CMatrixDense::save (const char name) const
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
		ofs << m_DenseToken << " " << "(" << m_Rows << "," << m_Columns << "):" << endl;
		for (size_t row_idx = 0; row_idx < m_Rows; row_idx++)
		{
			for (size_t column_idx = 0; column_idx < m_Columns; column_idx++)
				ofs << setw (m_ElementWidth) << setprecision (m_ElementPrecision)
					<< getElement (row_idx, column_idx) << " ";
			ofs << endl;
		}
		ofs.close ();
	}
}


