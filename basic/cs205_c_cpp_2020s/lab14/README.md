<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-09 09:03:21
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-07-01 13:57:29
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab14

### Exercise 1 - Function Template

Use the Max function to create a template and test it on different data types.

copy maxTemplate.cpp to your program .

``` cpp
/****************************************************
*
Compile and run the program to see how it works.
Make a template out of Max. Don't forget the return type.
Modify the prototype appropriately.
Test your Max template on int, double, and string types.
When you are done your output should resemble this:
Exercise 2 - Class Template
Complete the Matrix template types and Make the following program run correctly.
* FileName: maxTemplate.cpp
* Purpose: Demonstrate the use of function templates
*
********************************************************/
#include <iostream>
#include <string>
using namespace std;
//Make a template out of the prototype
int Max(int one, int two);
int main() {
    int i_one = 3, i_two = 5;
    cout << "The max of " << i_one << " and " << i_two << " is "
         << Max(i_one, i_two) << endl;
    //Test your template on float and string types
    return 0;
}
//Make a template out of this function. Don't forget the return type.
int Max(int one, int two) {
    int biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}
```

+ Compile and run the program to see how it works.
+ Make a template out of Max. Don't forget the return type.
+ Modify the prototype appropriately.
+ Test your Max template on int, double, and string types.

When you are done your output should resemble this:

``` log
The max of 3 and 5 is 5
The max of 5.6 and 7.3 is 7.3
The max of donkey and apple is donkey
```

### Exercise 2 - Class Template

Complete the Matrix template types and Make the following program run correctly.

``` cpp
#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;
template <typename T1>
void useMatrixTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);
int main() {
    string str1[MAXROWS][MAXCOLS] =
        {
            {"Congra", "y", "ar"},
            {"alm", "don", "La"}};
    string str2[MAXROWS][MAXCOLS] =
        {
            {"tulations", "ou", "e"},
            {"ost", "e the", "b!"}};
    int num1[MAXROWS][MAXCOLS] =
        {
            {1, 2, 3},
            {4, 5, 6}};
    int num2[MAXROWS][MAXCOLS] =
        {
            {6, 5, 4},
            {3, 2, 1}};
    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    cout << "\nDemonstrating with string matrix:" << endl;
    useMatrixTemplate(stringMatrix, str1, str2);
    cout << "\nDemonstrating with int matrix:" << endl;
    useMatrixTemplate(intMatrix, num1, num2);
    cout << "\n"
         << endl;
    return 0;
}
template <typename T1>
void useMatrixTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]) {
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();
    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
```

Here is a sample run of the program:

``` log
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
Demonstrating with float matrix:
Matrix set to first array
1.6 2.5 3.4
4.3 5.2 6.1
Matrix incremented by second array
7.7 7.7 7.7
7.7 7.7 7.7
```