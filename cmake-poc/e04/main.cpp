//
// Created by avictoria on 13/01/23.
//

#include <iostream>
#include "dog.h"
#include "operations.h"
#include "logger.h"

int main()
{
    // c++20
    auto value = ((10<=> 20) >0);
    std::cout << std::boolalpha ;
    std::cout << "value: " << value << std::endl;

    Dog dog1("pepe");
    dog1.printInfo();

    loggerData("Hello there", LoggerType::FATAL);

    double result = add(7, 5);
    std::cout << "Sum " << result << std::endl;
    
    return 0;
}
