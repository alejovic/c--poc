//
// Created by avictoria on 13/01/23.
//

#include <iostream>
#include "dog.h"
#include "operations.h"

int main()
{
    Dog dog1("pepe");
    dog1.printInfo();

    std::cout << "Hello World!" << std::endl ;
    std::cout << "Sum " << add(7, 5) << std::endl;
    
    return 0;
}
