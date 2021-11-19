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
 * @Date: 2020-04-30 19:59:02
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
#define CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H

#include <iostream>
#include <string>

class CandyBar {
private:
    std::string name;
    double weight;
    int calories;
public:

    explicit CandyBar();

    explicit CandyBar(const char *n, double w, int32_t cal);

    explicit CandyBar(const std::string &n, double w, int32_t cal);

    // 拷贝构造函数 Copy Constructor
    CandyBar(const CandyBar &s);

    // 移动构造函数
    CandyBar(CandyBar &&s);

    // 拷贝赋值运算符 Copy Assignment operator
    CandyBar &operator=(const CandyBar &) = delete;

    // 移动赋值运算符 Move Assignment operator
    CandyBar &operator=(CandyBar &&data);

    int32_t setCandyBar();

    void showCandyBar();

};

CandyBar get_a_candyBar();

#endif //CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
