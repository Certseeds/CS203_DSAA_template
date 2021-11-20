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
 * @Date: 2020-04-18 09:07:31
 * @LastEditors  : nanoseeds
 */
#include "fun.h"

int main() {
    double source[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double target1[5];
    double *target2 = new double[5];
    double *target3 = new double[5];
    CopyArray(target1, source);
    CopyArray(target2, source, 5);
    CopyArray(target3, source, &source[4]);
    PrintArray((double *) (&target1), target2, target3, 5);
    delete[] target2;
    delete[] target3;
    return 0;
}