//
// Created by lenovo on 2019/11/27.
//
//useComplex4.cpp -- using the 5th draft of the Complex class
#include "complex4.h"
#include <iostream>

using namespace std;

int main() {
    //Complex class before operator overloading
    Complex a(3.0, 4.0);
    Complex sum = 2.0 + a;

    cout << sum << endl << a;

    return 0;
}
