#include "IndentLogger.h"

#include <unistd.h>

void level2(void)
{
    LOG_iTRACE(NULL);

    LOG_TRACE("Start process ...");
    sleep(0.5);
    
    LOG_TRACE("Logger indent is: %i", Log::CIndentLogger::getIndent());
    LOG_TRACE("Logger elapsed time: %i", indentLogger_7.getElapsedTime());
    
    sleep(0.5);
    LOG_TRACE("End process ...");
}


void level1(bool b)
{
    LOG_iTRACE("Parameter: %i",b);
    if(b)
    {
        LOG_iTRACE("Enter level2");
        level2();
    }
    else
    {
        for(int i = 0;i < 7; ++i)
        {
            LOG_TRACE("Index: %i",i);
        }
    }
}

int main(int argc, char **argv)
{
    LOG_iTRACE(NULL);
    level1(false);
    level1(true);
    
	return 0;
}
