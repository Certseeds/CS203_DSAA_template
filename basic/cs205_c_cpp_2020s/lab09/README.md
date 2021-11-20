<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-09 08:29:41
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 08:40:22
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab09

1. Write a program that initializes an array of five double and then copies the contents of the array into three other
   arrays. Your requirements are as follows :
   This program consists of three files called fun.cpp, fun.h, and main.cpp

+ fun.h : contains the declaration of the following four functions
+ fun.cpp : source file that contains function definition in fun.h
+ main.cpp : main source file . all four arrays should be declared in main.cpp. To make

+ the first copy, use `void CopyArray(double(&target)[5], double (&source)[5])`;.
+ To make the second copy, use `void CopyArray(double *target, double *source, int len)`;
+ To make the third copy, use `void CopyArray(double *target, double *source_start, double *source_end)`;
+ Finally, invoke `void PrintArray(double *target1, double *target2, double *target3, int len)`;
+ print out the three copied arrays in the specified format. Write a Makefile file to organize all of three file for
  compilation.

``` cpp
// copy with reference notation
void CopyArray(double(&target)[5], double (&source)[5]);
// copy with pointer notation
void CopyArray(double *target, double *source, int len);
// copy with two pointers
void CopyArray(double *target, double *source_start, double
*source_end);
//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len);
```

A sample run might look like this:.

``` log
            target1|            target2|            target3|
              1.100|              1.100|              1.100|
              2.200|              2.200|              2.200|
              3.300|              3.300|              3.300|
              4.400|              4.400|              4.400|
              5.500|              5.500|              5.500|
```

2. The CandyBar structure contains three members. The first member holds the brand name of a candy bar. The second
   member holds the weight (which may have a fractional part) of the candy bar, and the third member holds the number of
   calories (an integer value) in the candy bar.

``` cpp
struct CandyBar{
    char brand[30];
    double weight;
    int calorie;
}
```

Here is a header file:

``` cpp
#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H
#include <iostream>
const int Len = 40;
struct CandyBar{
char brand[Len];
double weight;
int calorie;
};
// prompt the user to enter each of the preceding items of information and
// store them in the CandyBar structure
int setCandyBar(CandyBar & snack);
void showCandyBar(const CandyBar & snack);
#endif //EXC_CANDYBAR_H
```

Put together a **multi-file** program based on this header. One file, named candybar.cpp , should provide suitable
function definitions to match the prototypes in the header file. A second file should contain main() and demonstrate all
the features of the prototyped functions. For example,**use new to allocate the array dynamically , a loop should
solicit input for an array of CandyBar structures , terminate when the array is full or the user enters an empty string
for the CandyBar name and another loop should display all of CandyBar's information**. The main() function should use
only the prototyped functions to access the CandyBar structures.   
Finally,Write a Makefile file to organize all of three file for compilation.   
A sample run might look like this:

``` log
Please enter the number of candybar:
5
CandyBar[0]
Enter brand name of a Candy bar: new
Enter weight name of the candy bar: 23
Enter calories (an integer value) in the candy bar: 12
CandyBar[1]
Enter brand name of a Candy bar: old
Enter weight name of the candy bar: 23.4
Enter calories (an integer value) in the candy bar: 12
CandyBar[2]
Enter brand name of a Candy bar: 
empty name detected! 
```