#include <iostream>

#include <utils/index.h>
#include <kafka/index.h>
#include <rabbitMQ/index.h>

int main()
{
    utils::Log *log = new utils::Log();

    log->printLog("main()");
    log->printLog("utils::Log::printLog()");

    delete log;

    return 0;
}