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
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-18 09:07:41
 * @LastEditors  : nanoseeds
 */
#include "fun.h"
#include <iostream>
#include <iomanip>

void CopyArray(double(&target)[5], double (&source)[5]) {
    for (int i = 0; i < 5; ++i) {
        target[i] = source[i];
    }
}

// copy with pointer notation
void CopyArray(double *target, const double *source, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end) {
    for (int i = 0; i <= (source_end - source_start); ++i) {
        target[i] = source_start[i];
    }
}

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len) {
    const int interval = 20;
    std::cout << std::setw(interval) << "target1|" << std::setw(interval)
              << "target2|" << std::setw(interval) << "target3|" << std::endl;
    for (int i = 0; i < len; ++i) {
        std::cout << std::setw(interval - 1) << target1[i] << "|" << std::setw(interval - 1)
                  << target2[i] << "|" << std::setw(interval - 1) << target3[i] << "|" << std::endl;
    }
}
