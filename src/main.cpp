#include <iostream>
#include <boost/array.hpp>
#include <openssl/crypto.h>
#include <lib.hpp>
#include <vector>

using namespace std;

int main() {
    boost::array<int, 8> arr;
    arr[0] = 1;
    std::vector<int> vec;
    vec.push_back(123);
    MyClass1 a;
    MyClass2 b;
    a.SayHello();
    b.SayHello();
    #ifdef _WIN32
    cout << "Windows" << endl;
    #else
    cout << "Unix" << endl;
    #endif
    return 0;
}