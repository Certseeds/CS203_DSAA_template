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
 * @Date: 2020-04-18 09:07:41
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
#define CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H

// copy with reference notation
void CopyArray(double(&target)[5], double (&source)[5]);

// copy with pointer notation
void CopyArray(double *target, const double *source, int len);

// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end);

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len);

#endif //CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
