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

 * @Author: nanoseeds
 * @Date: 2020-05-07 22:04:08
 * @LastEditors  : nanoseeds
 */
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
