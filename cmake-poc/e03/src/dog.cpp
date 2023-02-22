//
// Created by avictoria on 13/01/23.
//
#include "dog.h"
#include <iostream>

Dog::Dog(std::string name) : dogName(name)
{
    std::cout << "Constructor for Dog " << dogName << " called. " << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog " << dogName << " called. " << std::endl;
}