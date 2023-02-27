//
// Created by avictoria on 13/01/23.
//

#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

class Dog
{
public:
    explicit Dog(std::string name);
    Dog() = default;
    ~Dog();

    std::string getName() const
    {
        return dogName;
    }

    void setName(const std::string &name)
    {
        dogName = name;
    }

    void printInfo()
    {
        std::cout << "Dog [ name: " << dogName << "]" << std::endl;
    }

private:
    std::string dogName {"lolo"};
};

#endif