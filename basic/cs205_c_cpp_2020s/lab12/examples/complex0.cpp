//
// Created by lenovo on 2019/11/27.
//
// Complex.cpp -- implementing Complex methods
#include <iostream>
#include "complex0.h"

Complex::Complex() : real(0), imag(0) {

}

Complex::Complex(double re, double im) : real(re), imag(im) {

}

Complex Complex::Sum(const Complex &data) {
    Complex sum;
    sum.imag = data.imag + this->imag;
    sum.real = data.real + this->real;
    return sum;
}

void Complex::Show() const {

    std::cout << real << "+" << imag << "i" << std::endl;
}

