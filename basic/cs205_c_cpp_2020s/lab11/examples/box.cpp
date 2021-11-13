


#include <iostream>
#include "box.h"

// Member functions definitions
box::box() {
    std::cout << "Object is being created" << std::endl;
    length = 3;
    breadth = 4;
    height = 5;
}

box::box(int length, int breadth, int height) {
    this->length = length;
    this->breadth = breadth;
    this->height = height;
}

box::box(const box &b) {
    length = b.length;
    breadth = b.breadth;
    height = b.height;
}

box::~box() {
    std::cout << "Object is being deleted" << std::endl;
}

double box::getVolume(void) {
    return length * breadth * height;
}

void box::setLength(double len) {
    length = len;
}

void box::setBreadth(double bre) {
    breadth = bre;
}

void box::setHeight(double hei) {
    height = hei;
}

