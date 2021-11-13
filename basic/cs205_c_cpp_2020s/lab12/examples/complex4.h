//
// Created by lenovo on 2019/11/27.
//
// Complex4.h -- Complex class after Overloading the  << operator for output
#ifndef EXAMPLE_COMPLEX1_H
#define EXAMPLE_COMPLEX1_H

#include <iostream>

class Complex {
public:
    Complex();

    Complex(double re, double im);

    void Show() const;

    Complex operator+(const Complex &other) const;

    Complex operator+(double r) const;

    friend Complex operator+(double r, const Complex &other);

    friend std::ostream &operator<<(std::ostream &os, const Complex &other);

private:
    double imag;
    double real;

};


#endif //EXAMPLE_COMPLEX1_H
