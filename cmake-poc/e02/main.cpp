//
// Created by avictoria on 13/01/23.
//
// Your First C++ Program

#include <iostream>
#include <concepts>

template <typename T>
requires  std::integral<T>
T add(T a, T b) {
    return a+b;
}

int main() {
    std::cout << "Hello World!" << std::endl;
    std::cout << "Sum " << add(7,5) << std::endl;
    return 0;
}
