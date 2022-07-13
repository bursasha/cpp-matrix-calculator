#ifndef MATRIXCALCULATOR_CEXCEPTION_H
#define MATRIXCALCULATOR_CEXCEPTION_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * @brief
 * A class responsible for possible exceptions that occur during the operation of the calculator.
 * */
class CException
{
public:
	/**
	 * @brief
	 * A basic constructor that initializes the message of the specific exception type.
	 * @param message - a string with a specific exception from the list of exceptions from CMessage.h
	 * */
	CException (const string& message)
	: m_Message (message) { }

	/**
	 * @brief
	 * A function responsible for the output of a specific exception depending on its type.
	 * @param log_destination - if true, outputs an exception to the ExceptionLog.txt; if false, outputs to the console.
	 *
	 * */
	void what (const bool log_destination) const;

private:
	/**
	 * @brief
	 * Holds a message of a specific exception.
	 * */
	string m_Message;

};

#endif // MATRIXCALCULATOR_CEXCEPTION_H
