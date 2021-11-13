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
#include "pizza.hpp"

using std::cin;
using std::cout;
using std::endl;

int sub_main_04_01();

#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04

int main() {
    const int32_t will_return = sub_main_04_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_04

int sub_main_04_01() {
    char *pizza_company = new char[lab04_01_max_length];
    memset(pizza_company, '\0', lab04_01_max_length);
    double diameter = 0.0f;
    double weight = 0.0f;
    cout << "Input name of the pizza : ";
    cin.getline(pizza_company, lab04_01_max_length);
    cout << "Input the diameter of pizza : ";
    cin >> diameter;
    cout << "Input the weight of pizza : ";
    cin >> weight;
    const auto *const pz = new pizza(pizza_company, diameter, weight);
    cout << "Name of the pizza : ";
    cout << pz->name << endl;
    cout << "diameter of the pizza : ";
    cout << (*(pz->diameter)) << endl;
    cout << "weight of the pizza : ";
    cout << (*(pz->weight)) << endl;
    delete pz;
    delete[] pizza_company;
    return 0;
}