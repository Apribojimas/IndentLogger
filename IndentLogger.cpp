#include "IndentLogger.h"

#include <stdarg.h>
#include <sstream>
#include <iomanip>


namespace Log
{

int CIndentLogger::_indent = 0;

CIndentLogger::CIndentLogger(const char* fileName, const char* funcName, int lineNumber, const char *fmt, ...)
: _fileName(fileName),_funcName(funcName)
{
    gettimeofday(&_startTime, NULL);

	if(fmt != NULL)
	{
		va_list args;
		va_start(args, fmt);
		char buffer[1024] = {0};
		vsnprintf(buffer, countof(buffer), fmt, args);
		std::cout << CIndentLogger::Format(">  ",fileName,funcName,lineNumber,buffer);
		va_end(args);
	}
	else
	{
		std::cout << CIndentLogger::Format(">  ",fileName,funcName,lineNumber,NULL);
	}

	_indent += 2;
}

CIndentLogger::~CIndentLogger()
{
	_indent -= 2;
	std::cout << CIndentLogger::Format("<  ",_fileName.c_str(),_funcName.c_str(),-1,getElapsedTime().c_str());
}

int CIndentLogger::getIndent(void)
{
    return CIndentLogger::_indent;
}

std::string CIndentLogger::getElapsedTime(void)
{
    timeval curTime;
    gettimeofday(&curTime, NULL);

    double elapsedTime;
    std::ostringstream ods_stream;

    // compute and print the elapsed time in millisec
    elapsedTime = (curTime.tv_sec - _startTime.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (curTime.tv_usec - _startTime.tv_usec) / 1000.0;   // us to ms

    ods_stream << "Elapsed time: " << elapsedTime << " ms.";

	return ods_stream.str();
}

char* CIndentLogger::getFormattedTime(void)
{
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer [80] = {0};
    // Returns the local date/time formatted as 2014-03-19 11:11:52
    // strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));
    // Returns the local date/time formatted as 11:11:52
    strftime(buffer, 40, "%H:%M:%S", localtime(&curTime.tv_sec));

    static char _retval[99] = {0};
    sprintf(_retval, "%s.%03d", buffer, milli);

    return _retval;
}

std::string CIndentLogger::Format(const char* prefix,const char* fileName, const char* funcName, int lineNumber, const char *fmt, ...)
{
	std::ostringstream ods_stream;
	std::string strIndent(CIndentLogger::_indent,' ');

	// PID
//	pthread_t thId = pthread_self();
//	ods_stream << "[" << std::setw(8) << thId << "] ";
	// Time & indent
	ods_stream << CIndentLogger::getFormattedTime() << " " << strIndent;
	// prefix
	if(prefix != NULL)
	{
		ods_stream << prefix;
	}
	// function name
	if(funcName != NULL)
	{
		ods_stream << funcName << "()";
	}
	// file name & line number
	if(fileName != NULL)
	{
		ods_stream << " - (" << fileName;
		if(lineNumber > -1)
		{
			ods_stream << ":" << std::setw(5) << lineNumber << ")";
		}
		else
		{
			ods_stream << ")";
		}
	}
	// extra message


	if(fmt != NULL)
	{
		va_list args;
		va_start(args, fmt);
		char buffer[1024] = {0};
		vsnprintf(buffer, countof(buffer), fmt, args);
		va_end(args);

		ods_stream << " -- " << buffer;
	}
	ods_stream << std::endl << std::flush;
	return ods_stream.str();
}


}