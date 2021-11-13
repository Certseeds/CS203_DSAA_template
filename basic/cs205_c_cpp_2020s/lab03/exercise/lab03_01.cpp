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
using std::string;

int sub_main_03_01();

#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03

int main() {
    const int32_t will_return = sub_main_03_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_03

int sub_main_03_01() {
    const CandyBar snack{"Mocha Munch", 2.3, 350};
    cout << "Brand: " << snack.name << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calorie: " << snack.calories << endl;
    return 0;
}