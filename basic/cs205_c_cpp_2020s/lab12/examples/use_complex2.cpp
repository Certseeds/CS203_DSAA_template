//
// Created by lenovo on 2019/11/27.
//
//useComplex2.cpp -- using the 3rd draft of the Complex class
#include "complex2.h"
#include <iostream>

using namespace std;

int main() {
    //Complex class before operator overloading
    Complex a(3.0, 4.0);
    Complex sum = a + 2.0;
    sum.Show();
    return 0;
}
