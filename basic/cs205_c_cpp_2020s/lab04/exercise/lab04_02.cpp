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
#include "CandyBar.hpp"

using std::cin;
using std::cout;
using std::endl;

int sub_main_04_02();

#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04

int main() {
    const int32_t will_return = sub_main_04_02();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_04

int sub_main_04_02() {
    char *name = new char[lab04_02_maxrange];
    double weight = 0;
    int32_t calories = 0;
    CandyBar *cb_array = new CandyBar[4];
    for (int i = 0; i < 3; i++) {
        memset(name, '\0', lab04_02_maxrange);
        cout << "Input name of the CandyBar : ";
        cin.getline(name, lab04_02_maxrange);
        cout << "Input the weight of CandyBar : ";
        cin >> weight;
        cout << "Input the calories of CandyBar : ";
        cin >> calories;
        cin.get();
        strncpy(cb_array[i].name, name, strlen(name) * sizeof(char));
        cb_array[i].name[strlen(name) * sizeof(char)] = '\0';
        (*cb_array[i].weight) = weight;
        (*cb_array[i].calories) = calories;
    }
    for (int i = 0; i < 3; i++) {
        cout << "name of the CandyBar " << i << " : ";
        cout << cb_array[i].name << endl;
        cout << "weight of the CandyBar " << i << " : ";
        cout << (*cb_array[i].weight) << endl;
        cout << "the calories of CandyBar " << i << " : ";
        cout << (*cb_array[i].calories) << endl;
    }
    delete[] name;
    delete[] cb_array;
    return 0;
}