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
 * @Date: 2020-05-23 11:20:35
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
#define CS205_C_CPP_LAB14_EXERCISE_MATRIX_H

#include <iostream>
#include <cstdint>

static constexpr const int32_t MAXROWS = 2;
static constexpr const int32_t MAXCOLS = 3;

// header file for lab14_02.cpp
template<typename T>
class Matrix {
private:
    T matrix[MAXROWS][MAXCOLS];
    int32_t rows;
    int32_t cols;
public:
    Matrix();

    void printMatrix();

    void setMatrix(T mat[][MAXCOLS]); //set the Array to what is sent
    void addMatrix(T mat[][MAXCOLS]); //add an array to matrix
    void addMatrix(Matrix otherMatrix);
};

template<typename T>
Matrix<T>::Matrix() {
    rows = MAXROWS;
    cols = MAXCOLS;
}

template<typename T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
void Matrix<T>::setMatrix(T mat[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = mat[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::addMatrix(T mat[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += mat[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::addMatrix(Matrix<T> otherMatrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += otherMatrix[i][j];
        }
    }
}

#endif //CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
