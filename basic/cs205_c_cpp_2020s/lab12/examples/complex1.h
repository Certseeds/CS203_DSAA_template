//
// Created by lenovo on 2019/11/27.
//
// Complex1.h -- Complex class after Operator+ overloaded
#ifndef EXAMPLE_COMPLEX1_H
#define EXAMPLE_COMPLEX1_H


class Complex {
public:
    Complex();

    Complex(double re, double im);

    void Show() const;

    Complex operator+(const Complex &other) const;

private:
    double imag;
    double real;

};


#endif //EXAMPLE_COMPLEX1_H
