#include <iostream>
#include <chrono>
#include <ctime>

#include <utils/index.h>

int main()
{
    utils::FileLogger *fileLogger = new utils::FileLogger();
    fileLogger->log(utils::FileLogger::INFO, "main()");
    delete fileLogger;

    utils::FileLogger *fileLogger1 = new utils::FileLogger();
    fileLogger1->log(utils::FileLogger::DEBUG, "This message is to test the package");
    delete fileLogger1;

    utils::FileLogger *fileLogger2 = new utils::FileLogger();
    fileLogger2->log(utils::FileLogger::WARN, "Error!!");
    fileLogger2->log(utils::FileLogger::ERROR, "Error!!");

    fileLogger2->logMeta(utils::FileLogger::INFO, "Started", __FILE__, __LINE__, __func__);
    fileLogger2->logMeta(utils::FileLogger::ERROR, "Started", __FILE__, __LINE__, __func__);
    fileLogger2->logMeta(utils::FileLogger::WARN, "Started", __FILE__, __LINE__, __func__);

    delete fileLogger2;



    

    utils::ConsoleLogger *consoleLogger = new utils::ConsoleLogger();
    consoleLogger->info("main()");
    delete consoleLogger;

    utils::ConsoleLogger *consoleLogger1 = new utils::ConsoleLogger();
    consoleLogger1->info("This message is to test the package");
    delete consoleLogger1;

    utils::ConsoleLogger *consoleLogger2 = new utils::ConsoleLogger();
    consoleLogger2->info("Error!!");
    delete consoleLogger2;

    return 0;
}