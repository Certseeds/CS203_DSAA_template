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
 * @Date: 2020-04-02 18:08:01
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <functional>

static constexpr const int32_t row = 52;

void outputLine(const int &number, const char &ch);

void displaymenu();

int32_t Add(int32_t a, int32_t b);

int32_t Substract(int32_t a, int32_t b);

int32_t Multiply(int32_t a, int32_t b);

int32_t Divide(int32_t a, int32_t b);

int32_t Modules(int32_t a, int32_t b);


using std::cin;
using std::cout;
using std::endl;

int main() {
    std::function<int32_t(int32_t, int32_t)> func_array[]{Add, Substract, Multiply, Divide, Modules};
    char conti = 'Y';
    int32_t num1 = 0;
    int32_t num2 = 0;
    int32_t choice = 0;
    do {
        displaymenu();
        cout << "Enter your choice(1-5):";
        cin >> choice;
        if (choice <= 0 || choice >= 6) {
            cout << "Wrong choice, default use 0" << endl;
            choice = 1;
        }
        cout << "Enter your two integer numbers: ";
        cin >> num1 >> num2;
        cout << "Result:" << func_array[choice - 1](num1, num2) << endl;
        cout << "Press y or Y to continue:" << endl;
        cin >> conti;
    } while ('Y' == conti || 'y' == conti);
    return 0;
}

void outputLine(const int32_t &number, const char &ch) {
    for (int i = 0; i < number; i++) {
        cout << ch;
    }
}

void displaymenu() {
    outputLine(row, '=');
    cout << endl;
    outputLine(row / 2, ' ');
    cout << "MENU" << endl;
    outputLine(row, '=');
    cout << endl;
    cout << "   1.Add" << endl;
    cout << "   2.Subtract" << endl;
    cout << "   3.Multiply" << endl;
    cout << "   4.Divide" << endl;
    cout << "   5.Modulus" << endl;
    cout << endl;
}

int32_t Add(int32_t a, int32_t b) {
    return a + b;
}

int32_t Substract(int32_t a, int32_t b) {
    return a - b;
}


int32_t Multiply(int32_t a, int32_t b) {
    return a * b;
}

int32_t Divide(int32_t a, int32_t b) {
    return a / b;
}

int32_t Modules(int32_t a, int32_t b) {
    return a % b;
}