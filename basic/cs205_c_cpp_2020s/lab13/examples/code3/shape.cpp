//
// Created by lenovo on 2019/12/4.
//
// Shape.cpp -- Shape class methods
#include <iostream>
#include "shape.h"

using namespace std;
int shape::numberOfObjects = 0;

// protected methods for formatting
Formatting shape::SetFormat() const {
    // set up ###.## format
    Formatting f{};
    f.flag =
            cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(3);
    return f;
}

void shape::Restore(Formatting &f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}


void shape::Show() {
    // set up ###.## format
    Formatting flag = SetFormat();
    std::cout << "The Shape!" << std::endl;
    // Restore original format
    Restore(flag);
}

double shape::GetArea() const {
    std::cout << "The Shape::GetArea!" << std::endl;
    return 0;
}