//
// Created by lenovo on 2019/11/27.
//
//useComplex1.cpp -- using the second draft of the Complex class
#include "complex1.h"
#include <iostream>

using namespace std;

int main() {
    //Complex class before operator overloading
    Complex a(3.0, 4.0);
    Complex b(5.0, 6.0);
    Complex sum = a.operator+(b);
    //Complex sum = a+b;

    sum.Show();

    return 0;
}
