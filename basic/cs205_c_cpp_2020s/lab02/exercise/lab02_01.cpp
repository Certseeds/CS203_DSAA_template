/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-28 07:49:01
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-28 09:59:17
 */
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
#include <iostream>
#include <vector>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int sub_main_02_01();

#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02

int main() {
    const int32_t will_return = sub_main_02_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_02

int sub_main_02_01() {
    cout << "Result:" << endl;
    printf("%-2s%-s %-2s%s  %s%-5s%s\n", "x", "value",
           "y", "value", "Expressions", " ", "Result");
    //cout << "x value y value  Expressions   Result"<<endl;
    static constexpr const int x = 10;
    static constexpr const int y = 5;
    static constexpr const char *const str1[5]{"y+3", "y-2", "y*5", "x/y", "x%y"};
    vector<int> str2{y + 3, y - 2, y * 5, x / y, x % y};
    for (int i = 0; i < 5; i++) {
        printf("%-3d|%4s%-2d|%6s", x, " ", y, " ");
        printf("x=%-14s|x=%-4d", str1[i], str2[i]);
        cout << endl;
    }
    return 0;
}