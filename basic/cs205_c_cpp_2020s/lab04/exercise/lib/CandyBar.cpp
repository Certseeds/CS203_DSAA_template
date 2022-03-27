// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
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
