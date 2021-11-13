//
// Created by lenovo on 2019/12/4.
//
// Circle.cpp -- Circle class methods
#include "circle.h"
#include <iostream>

circle::circle(circle &C) {
    radius = C.radius;

}

circle::circle(double radius) : radius(radius) {

}

circle::~circle() {

}

double circle::GetRadius() {
    return radius;
}

double circle::GetArea() const {
    return PI * radius * radius;
}

void circle::Show() {
    // set up ###.## format
    Formatting flag = SetFormat();

    std::cout << "radius:" << radius
              << "\tthe area :" << GetArea() << std::endl;
    // Restore original format
    Restore(flag);
}
