//
// Created by lenovo on 2019/12/4.
//
// Rectangle.cpp -- Rectangle class methods
#include <iostream>
#include "rectangle.h"

rectangle::rectangle(rectangle &rectangle) {
    width = rectangle.width;
    height = rectangle.height;

}

rectangle::rectangle(double width, double height) {
    this->width = width;
    this->height = height;

}

double rectangle::GetArea() const {
    return width * height;
}

void rectangle::Show() {
    // set up ###.## format
    Formatting flag = SetFormat();
    std::cout << "width:" << width
              << "\theight:" << height
              << "\tthe area :" << GetArea() << std::endl;
    // Restore original format
    Restore(flag);
}