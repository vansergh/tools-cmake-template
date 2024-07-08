#include "lib.hpp"
#include <iostream>

void MyClass2::SayHello() {
    std::cout << "Hello from Class2" << std::endl;
    std::cout << "Macro1: " << VAR1 << std::endl;
    std::cout << "Macro2: " << VAR2 << std::endl;
}