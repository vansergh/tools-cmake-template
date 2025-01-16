#include "../lib.hpp"
#include <iostream>

void MyClass1::SayHello(){
    std::cout << "Hello from Class1" << std::endl;
    std::cout << "Macro 1: " << VAR1 << std::endl;
}