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

#include "CandyBar.hpp"

CandyBar::CandyBar() {
    name = new char[lab04_02_maxrange];
    memset(name, '\0', lab04_02_maxrange);
    weight = new double;
    calories = new int32_t;
}

CandyBar::CandyBar(char *n, double d, int32_t w) {
    name = new char[lab04_02_maxrange];
    weight = new double;
    calories = new int32_t;
    memset(name, '\0', lab04_02_maxrange);
    memcpy(name, n, strlen(n) * sizeof(char));
    (*weight) = d;
    (*calories) = w;
}

CandyBar::~CandyBar() {
    delete[] name;
    delete weight;
    delete calories;
}
