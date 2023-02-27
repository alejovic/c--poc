//
// Created by avictoria on 13/01/23.
//
#include "logger.h"
#include <iostream>

void loggerData(const char *message, LoggerType loggerType)
{
    switch (loggerType)
    {
    case LoggerType::FATAL:
        std::cout << "FATAL: " << message << std::endl;
        break;
    case LoggerType::WARNING:
        std::cout << "WARNING: " << message << std::endl;
        break;
    case LoggerType::MESSAGE:
        std::cout << "MESSAGE: " << message << std::endl;
        break;

    default:
        break;
    }
}