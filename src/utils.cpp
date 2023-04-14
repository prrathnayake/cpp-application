#include <iostream>
#include <chrono>
#include <ctime>

#include <utils/index.h>

int main()
{
    utils::FileLogger *fileLogger = new utils::FileLogger();
    fileLogger->info("main()");
    delete fileLogger;

    utils::ConsoleLogger *consoleLogger = new utils::ConsoleLogger();
    consoleLogger->info("main()");
    delete consoleLogger;

    return 0;
}