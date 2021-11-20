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
 * @Date: 2020-04-18 10:25:34
 * @LastEditors  : nanoseeds
 */
#include "CandyBar.h"
#include <iostream>
#include <cstring>

int setCandyBar(CandyBar &snack) {
    while ((getchar()) != '\n');
    char name[40];
    double weight;
    int calorie;
    std::cout << "Enter brand name of a Candy bar: ";
    std::cin.getline(name, Len);
    if (0 == std::strlen(name)) {
        std::cout << std::endl;
        std::cout << "empty name detected!" << std::endl;
        return -1;
    }
    std::cout << "Enter weight name of the candy bar: ";
    std::cin >> weight;
    std::cout << "Enter calories (an integer value) in the candy bar: ";
    std::cin >> calorie;
    std::memcpy(snack.brand, name, Len);
    snack.weight = weight;
    snack.calorie = calorie;
    return 0;
}

void showCandyBar(const CandyBar &snack) {
    std::cout << "Brand: " << snack.brand << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "Calorie: " << snack.calorie << std::endl;
}