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
#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double re, double im) : real(re), imag(im) {}

Complex::Complex(const Complex &s) : Complex(s.real, s.imag) {}

Complex Complex::operator+(const Complex &other) const {
    return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::operator+(double r) const {
    return Complex(this->real + r, this->imag);
}

Complex operator+(double r, const Complex &other) {
    return other + r;
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
}

Complex Complex::operator-(double r) const {
    return Complex(this->real - r, this->imag);
}

Complex operator-(double r, const Complex &other) {
    return Complex(r - other.real, other.imag);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(this->real * other.real - this->imag * other.imag,
                   this->real * other.imag + this->imag * other.real);
}

Complex Complex::operator*(double r) const {
    return Complex(this->real * r, this->imag * r);
}

Complex operator*(double r, const Complex &other) {
    return other * r;
}

Complex Complex::operator~() const {
    return Complex(this->real, -1 * this->imag);
}

bool Complex::operator==(const Complex &other) const {
    return this->real == other.real && this->imag == other.imag;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &output, const Complex &other) {
    output << other.real << "+" << other.imag << "i";
    return output;
}

std::istream &operator>>(std::istream &in, Complex &other) {
    std::cout << "real: ";
    in >> other.real;
    std::cout << "imaginary: ";
    in >> other.imag;
    return in;
}

