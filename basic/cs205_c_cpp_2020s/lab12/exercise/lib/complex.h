/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
/**
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:03:19
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB12_EXERCISE_COMPLEX_H
#define CS205_C_CPP_LAB12_EXERCISE_COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    explicit Complex();

    explicit Complex(double re, double im);


    // 拷贝构造函数 Copy Constructor
    Complex(const Complex &s);

    // 移动构造函数
    Complex(Complex &&s) = delete;

    // 拷贝赋值运算符 Copy Assignment operator
    Complex &operator=(const Complex &) = delete;

    // 移动赋值运算符 Move Assignment operator
    Complex &operator=(Complex &&data) = delete;

    Complex operator+(const Complex &other) const;

    Complex operator+(double r) const;

    friend Complex operator+(double r, const Complex &other);

    Complex operator-(const Complex &other) const;

    Complex operator-(double r) const;

    friend Complex operator-(double r, const Complex &other);

    Complex operator~() const;

    Complex operator*(const Complex &other) const;

    Complex operator*(double r) const;

    friend Complex operator*(double r, const Complex &other);

    friend std::ostream &operator<<(std::ostream &os, const Complex &other);

    friend std::istream &operator>>(std::istream &os, Complex &other);

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;
};


#endif //CS205_C_CPP_LAB12_EXERCISE_COMPLEX_H
