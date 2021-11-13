/**
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:50:49
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
#include "CandyBar.h"

using std::cin;
using std::cout;
using std::endl;

int sub_main_03_02();

#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03

int main() {
    const int32_t will_return = sub_main_03_02();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_03

int sub_main_03_02() {
    char temp_name[1024];
    double weight = 0.0f;
    int calories = 0;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(temp_name, 1024, '\n');
    cout << "Enter weight of the candy bar: ";
    cin >> weight;
    cout << "Enter calories(an integer value) in the Candy bar: ";
    cin >> calories;
    CandyBar cb_1{temp_name, weight, calories};
    cout << "Brand: " << cb_1.name << endl;
    cout << "Weight: " << cb_1.weight << endl;
    cout << "Calorie: " << cb_1.calories << endl;
    return 0;
}