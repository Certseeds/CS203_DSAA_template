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
 * @Date: 2020-04-18 10:24:28
 * @LastEditors  : nanoseeds
 */
#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H

#include <iostream>

const int Len = 40;
struct CandyBar {
    char brand[Len];
    double weight;
    int calorie;
};

// prompt the user to enter each of the preceding items of information and
// store them in the CandyBar structure
int setCandyBar(CandyBar &snack);

void showCandyBar(const CandyBar &snack);

#endif //EXC_CANDYBAR_H