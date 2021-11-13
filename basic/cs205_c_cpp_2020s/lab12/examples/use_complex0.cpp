//
// Created by lenovo on 2019/11/27.
//
//useComplex0.cpp -- using the first draft of the Complex class
#include "complex0.h"
#include <iostream>

using namespace std;

int main() {
    //Complex class before operator overloading
    Complex a(3.0, 4.0);
    Complex b(5.0, 6.0);
    Complex sum = a.Sum(b);
    sum.Show();

    return 0;
}
