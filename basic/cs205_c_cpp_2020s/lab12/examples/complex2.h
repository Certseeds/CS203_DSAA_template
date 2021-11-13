//
// Created by lenovo on 2019/11/27.
//
// Complex2.h -- Complex class before adding Friend functions
#ifndef EXAMPLE_COMPLEX1_H
#define EXAMPLE_COMPLEX1_H


class Complex {
public:
    Complex();

    Complex(double re, double im);

    void Show() const;

    Complex operator+(const Complex &other) const;

    Complex operator+(double real) const;

private:
    double imag;
    double real;

};


#endif //EXAMPLE_COMPLEX1_H
