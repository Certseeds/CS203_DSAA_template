//
// Created by lenovo on 2019/12/4.
//
// Circle.cpp -- Circle class methods
#include "circle.h"
#include <iostream>

int circle::numberOfObjects = 0;

circle::circle(circle &C) {
    radius = C.radius;
    numberOfObjects++;
}

circle::circle(double radius) : radius(radius) {
    numberOfObjects++;
}

circle::~circle() {
    numberOfObjects++;
}

double circle::GetRadius() {
    return radius;
}

double circle::GetArea() const {
    return PI * radius * radius;
}

void circle::Show() {

    std::cout << "radius:" << radius
              << "\tthe area :" << GetArea() << std::endl;
}
