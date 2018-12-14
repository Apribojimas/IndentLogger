#ifndef __INDENT_LOGGER_H__
#define __INDENT_LOGGER_H__

#include <string>
#include <iostream>
#include <sys/time.h>


#define countof(arr) sizeof(arr) / sizeof(arr[0])
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define CAT2(X,Y) X##Y
#define CAT(X,Y) CAT2(X,Y)

namespace Log
{

class CIndentLogger
{
public:
	CIndentLogger(const char* fileName, const char* funcName, int lineNumber, const char *fmt, ...);
	virtual ~CIndentLogger();

    static int getIndent(void);
	std::string getElapsedTime(void);

	static std::string Format(const char* prefix,const char* fileName, const char* funcName, int lineNumber, const char *fmt, ...);
	static char* getFormattedTime(void);
    
protected:
	std::string _fileName;
	std::string _funcName;
	timeval _startTime;
	static int _indent;
};

}

//#define __INDENT_LOGGER__ // turn off logging
#ifndef __INDENT_LOGGER__

//#define LOG_iTRACE(...) Log::CIndentLogger indentLogger(__FILE__, __func__, __LINE__,##__VA_ARGS__);
#define LOG_iTRACE(...) Log::CIndentLogger CAT(indentLogger_,__LINE__)(__FILE__, __func__, __LINE__,##__VA_ARGS__);
#define LOG_TRACE(...) std::cout << Log::CIndentLogger::Format("|  ",__FILE__, __func__, __LINE__,##__VA_ARGS__)

#else

#define LOG_iTRACE(...) {}
#define LOG_TRACE {}

#endif



#endif // __INDENT_LOGGER_H__INDENT_LOGGER_H
