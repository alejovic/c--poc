//
// Created by avictoria on 13/01/23.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

enum class LoggerType{
        MESSAGE,
        WARNING,
        FATAL
};

void loggerData(const char* messsage, LoggerType logger);

#endif