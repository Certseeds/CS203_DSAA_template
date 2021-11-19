<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 23:11:33
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:38:06
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04),C++17, Cmake 3.16.6.

# Lab12 Exercise: 2020_0507

## E1 Code & Result

### Code

1. Complex.h

``` cpp
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
```

2. Complex.cpp

``` cpp
#include "Complex.h"
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
```

3. lab12_01.cpp

``` cpp
#include "Complex.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is" << (b != c) << endl;
    cout << "a==c is" << (a == c) << endl << endl;
    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input:
    4
    6
Output:
    b is 2+6i
    ~b is 2+-6i
    a is 3+4i
    a + b is 5+10i
    a - b is 1+-2i
    a * b is -18+26i
    2 * b is 4+12i
    b==c is 1
    b!=c is0
    a==c is0
    d is 4+6i
```

![picture_01](./lab12_01.png)

## E2 Code & Result

### Code

1. Number.h

``` cpp
#ifndef CS205_C_CPP_LAB12_EXERCISE_NUMBER_H
#define CS205_C_CPP_LAB12_EXERCISE_NUMBER_H
#include <iostream>
#include <cstdint>
class Number {
private:
    int64_t number;
public:
    explicit Number() : number(0) {};
    explicit Number(int64_t v) : number(v) {};
    // 拷贝构造函数 Copy Constructor
    Number(const Number &s) = default;
    // 移动构造函数
    Number(Number &&s) = delete;
    // 拷贝赋值运算符 Copy Assignment operator
    Number &operator=(const Number &) = delete;
    // 移动赋值运算符 Move Assignment operator
    Number &operator=(Number &&data) = delete;
    Number operator++();
    Number operator++(int);
    Number operator--();
    Number operator--(int);
    friend std::ostream &operator<<(std::ostream &os, const Number &other);
};
#endif //CS205_C_CPP_LAB12_EXERCISE_NUMBER_H
```

2. Number.cpp

``` cpp
#include "Number.h"
Number Number::operator++() { // 前缀
    return Number(++number);
}
Number Number::operator++(int) {
    return Number(number++);
}
Number Number::operator--() { // 前缀
    return Number(--number);
}
Number Number::operator--(int) {
    return Number(number--);
}
std::ostream &operator<<(std::ostream &os, const Number &other) {
    os << "x = " << other.number;
    return os;
}
```

3. lab12_02.cpp

``` cpp
#include <iostream>
#include "Number.h"
using std::cout;
using std::endl;
int main() {
    Number n1(20);
    Number n2 = n1++;
    cout << n1 << endl;
    cout << n2 << endl;
    Number n3 = n2--;
    cout << n2 << endl;
    cout << n3 << endl;
    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;
    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;
    return 0;
}
```

### Result

#### Test Case #1:

``` log
Input:
    no input
Output:
    x = 21
    x = 20
    x = 19
    x = 20
    x = 21
    x = 21
    x = 20
    x = 20
```

![picture_02](./lab12_02.png)