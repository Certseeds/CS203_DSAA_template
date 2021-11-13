<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-23 11:50:05
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:40:24
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 18.04),C++17, Cmake 3.16.6.

# Lab14 Exercise: 2020_0521

## E1 Code & Result

### Code

1. lab14_01.cpp

``` cpp
#include <iostream>
#include <string>
using namespace std;
//Make a template out of the prototype
template<typename T>
T Max(T one, T two);
int main() {
    int i_one = 3, i_two = 5;
    cout << "The max of " << i_one << " and " << i_two << " is "
         << Max<int>(i_one, i_two) << endl;
//Test your template on float and string types
    double double_one = 5.6f, double_two = 7.3f;
    cout << "The max of " << double_one << " and " << double_two << " is "
         << Max<double>(double_one, double_two) << endl;
    string str_one = "donkey", str_two = "apple";
    cout << "The max of " << str_one << " and " << str_two << " is "
         << Max<string>(str_one, str_two) << endl;
    return 0;
}
template<typename T>
T Max(T one, T two) {
    T biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}
```

### Result

#### Test Case #1

``` log
Input:
    no input
Output:
    The max of 3 and 5 is 5
    The max of 5.6 and 7.3 is 7.3
    The max of donkey and apple is donkey
```

![picture_01](./lab14_01.png)

## E2 Code & Result

### Code

1. matrix.h

``` cpp
#ifndef CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
#define CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
#include <iostream>
#include <cstdint>
const int32_t MAXROWS = 2;
const int32_t MAXCOLS = 3;
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
```

2. lab14_02.cpp

``` cpp
#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;
template<typename T1>
void useMatrixTemplate(Matrix<T1> &M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);
int main() {
    string str1[MAXROWS][MAXCOLS] =
            {
                    {"Congra", "y",   "ar"},
                    {"alm",    "don", "La"}
            };
    string str2[MAXROWS][MAXCOLS] =
            {
                    {"tulations", "ou",    "e"},
                    {"ost",       "e the", "b!"}
            };
    int num1[MAXROWS][MAXCOLS] =
            {
                    {1, 2, 3},
                    {4, 5, 6}
            };
    int num2[MAXROWS][MAXCOLS] =
            {
                    {6, 5, 4},
                    {3, 2, 1}
            };
    double dou1[MAXROWS][MAXCOLS] =
            {
                    {1.6f, 2.5f, 3.4f},
                    {4.3f, 5.2f, 6.1f}
            };
    double dou2[MAXROWS][MAXCOLS] =
            {
                    {6.1f, 5.2f, 4.3f},
                    {3.4f, 2.5f, 1.6f}
            };
    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    Matrix<double> doubleMatrix;
    cout << "\nDemonstrating with string matrix:" << endl;
    useMatrixTemplate(stringMatrix, str1, str2);
    cout << "\nDemonstrating with int matrix:" << endl;
    useMatrixTemplate(intMatrix, num1, num2);
    cout << "\nDemonstrating with double matrix:" << endl;
    useMatrixTemplate(doubleMatrix, dou1, dou2);
    cout << "\n" << endl;
    return 0;
}
template<typename T1>
void useMatrixTemplate(Matrix<T1> &M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]) {
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();
    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
```

### Result

#### Test Case #1

``` log
Input:
    no input
Output:
    
    Demonstrating with string matrix:

    Matrix set to first array
    Congra y ar 
    alm don La 

    Matrix incremented by second array
    Congratulations you are 
    almost done the Lab! 

    Demonstrating with int matrix:

    Matrix set to first array
    1 2 3 
    4 5 6 

    Matrix incremented by second array
    7 7 7 
    7 7 7 

    Demonstrating with double matrix:

    Matrix set to first array
    1.6 2.5 3.4 
    4.3 5.2 6.1 

    Matrix incremented by second array
    7.7 7.7 7.7 
    7.7 7.7 7.7 
```

![picture_02](./lab14_02.png)