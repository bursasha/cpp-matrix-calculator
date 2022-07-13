#include "CException.h"
#include "CMessage.h"

void CException::what (const bool log_destination) const
{
	if (log_destination)
	{
		ofstream ofs ("ExceptionLog.txt");
		(!ofs.is_open ()) ? cerr << CErrorMessage ["BAD_LOG"] : ofs << m_Message;
		ofs.close ();
	}

	else cerr << m_Message << endl;
}
