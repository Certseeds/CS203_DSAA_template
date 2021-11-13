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
 * @Date: 2020-04-30 20:44:46
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include "lib/candy_bar.h"

int main() {
    CandyBar cb; // 构造函数 无参
    cb.setCandyBar();
    cb.showCandyBar();
    CandyBar cb2("Zhanche", 19.2f, 11); // 构造函数 1
    CandyBar cb3(std::string("Yinzhe"), 11.4f, 19); // 构造函数 2
    CandyBar cb4(cb); // 拷贝构造函数
    CandyBar cb5 = std::move(cb4); // 移动构造函数
    CandyBar cb6 = cb5; // 拷贝构造函数
    CandyBar cb7 = CandyBar("Diao DIao ren", 81.0f, 9); // 默认构造函数
    CandyBar cb8 = std::move(CandyBar("Sum", 48.0f, 4)); // 移动构造函数
    CandyBar cb9 = get_a_candyBar();
    CandyBar cb10;
    cb10 = std::move(cb9); // 移动赋值运算符
    CandyBar cb11; // 构造函数 无参
    cb11 = get_a_candyBar(); // 构造函数 1,然后移动赋值运算符.
    // cb11 = cb10; can not do copy 赋值
    return 0;
}