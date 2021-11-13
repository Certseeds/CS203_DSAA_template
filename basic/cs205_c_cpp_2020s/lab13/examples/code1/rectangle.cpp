//
// Created by lenovo on 2019/12/4.
// Rectangle.cpp -- Rectangle class methods
#include <iostream>
#include "rectangle.h"

int rectangle::numberOfObjects = 0;

rectangle::rectangle(rectangle &rectangle) {
    width = rectangle.width;
    height = rectangle.height;
    numberOfObjects++;
}

rectangle::rectangle(double width, double height) {
    this->width = width;
    this->height = height;
    numberOfObjects++;
}

double rectangle::GetArea() const {
    return width * height;
}

void rectangle::Show() {
    std::cout << "width:" << width
              << "\theight:" << height
              << "\tthe area :" << GetArea() << std::endl;
}