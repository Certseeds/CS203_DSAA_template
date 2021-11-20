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
 * @Date: 2020-04-10 22:16:13
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
static constexpr const int32_t brand_length = 29;
struct CandyBar {
    char brand[brand_length + 1];
    double weight;
    int32_t calorie;
};

void set(CandyBar &cb);

void set(CandyBar *const cb);

void show(const CandyBar &cb);

void show(const CandyBar *cb);

int32_t main() {
    CandyBar cd1{};
    set(&cd1);
    show(&cd1);
    while ((getchar()) != '\n');
    set(cd1);
    show(cd1);
    return 0;
}

void set(CandyBar &cb) {
    cout << "Call the set function of passing by reference:" << endl;
    char brand_input[brand_length * 10 + 1];
    double weight_input = 0.0f;
    int32_t calorie_input = 0;
    memset(brand_input, '\0', brand_length + 1);
    cout << "Enter brand name of a Candty bar: ";
    cin.getline(brand_input, brand_length);
    cout << "Enter weight of the candy bar: ";
    cin >> weight_input;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> calorie_input;
    memcpy(cb.brand, brand_input, (brand_length + 1) * sizeof(char));
    cb.weight = weight_input;
    cb.calorie = calorie_input;
}

void set(CandyBar *const cb) {
    cout << "Call the set function of passing by pointer:" << endl;
    char brand_input[brand_length * 10 + 1];
    double weight_input = 0.0f;
    int32_t calorie_input = 0;
    memset(brand_input, '\0', brand_length + 1);
    cout << "Enter brand name of a Candty bar: ";
    cin.getline(brand_input, brand_length);
    cout << "Enter weight of the candy bar: ";
    cin >> weight_input;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> calorie_input;
    memcpy(cb->brand, brand_input, (brand_length + 1) * sizeof(char));
    cb->weight = weight_input;
    cb->calorie = calorie_input;
}

void show(const CandyBar &cb) {
    cout << "Call the show function of Passing by reference: " << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "calories: " << cb.calorie << endl;
}

void show(const CandyBar *cb) {
    cout << "Call the show function of Passing by pointer: " << endl;
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "calories: " << cb->calorie << endl;
}