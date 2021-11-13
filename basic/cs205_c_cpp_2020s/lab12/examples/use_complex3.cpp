//
// Created by lenovo on 2019/11/27.
//
//useComplex3.cpp -- using the 4th draft of the Complex class
#include "complex3.h"
#include <iostream>

using namespace std;

int main() {
    //Complex class before operator overloading
    Complex a(3.0, 4.0);
    Complex sum = 2.0 + a;
    sum.Show();

    return 0;
}
