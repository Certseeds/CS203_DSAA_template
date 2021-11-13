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
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int sub_main_04_03();

#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04

int main() {
    const int32_t will_return = sub_main_04_03();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_04
static constexpr const int32_t lab04_03_range = 5;

int sub_main_04_03() {
    auto *five_array = new int32_t[lab04_03_range];
    int32_t *temp = five_array;
    memset(five_array, 0, lab04_03_range * sizeof(int32_t));
    for (int32_t i = 0; i < lab04_03_range; i++) {
        cout << "Input number " << i << " : ";
        cin >> (*temp);
        temp++;
        cin.get();
    }
    for (int32_t i = 0; i < lab04_03_range; i++) {
        temp--;
        cout << "number " << i << " is : ";
        cout << (*temp) << endl;
    }
    delete[] five_array;
    return 0;
}