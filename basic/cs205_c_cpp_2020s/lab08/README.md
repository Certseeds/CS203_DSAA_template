<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-09 08:09:41
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 08:31:43
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab08

1. The CandyBar structure contains three members.The first member holds the brand name of a candy bar.The second member
   holds the weight (which may have a fractional part) of the candy bar, and the third member holds the number of
   calories (an integer value) in the candy bar.

``` cpp
struct CandyBar{
    char brand[30];
    double weight;
    int calorie;
}
```

Write the following functions:

+ `void set(CandyBar & cb)`, that should ask the user to enter each of the preceding items of information to set the
  corresponding members of the structure.
+ `void set(CandyBar* const cb)` ,that is a overloading function .
+ `void show(const CandyBar & cb)`,that displays the contents of the structure.
+ `void show(const CandyBar* cb)`,that is a overloading function . Write a simple program that uses these four
  functions.

A sample run might look like this:.

``` log
Call the set function of passing by pointer:
Enter brand name of a Candty bar: Millennium Munch
Enter weight of the candy bar: 2.85
Enter calories (an integer value) in the candy bar: 350
Call the show function of Passing by pointer: 
Brand: Millennium Munch
Weight: 2.85
calories: 350
Call the set function of passing by reference:
Enter brand name of a Candty bar: Millennium Munch
Enter weight of the candy bar: 3.85
Enter calories (an integer value) in the candy bar: 361
Call the show function of Passing by reference: 
Brand: Millennium Munch
Weight: 3.85
```

2. Write a template function max5() that takes as its argument an array of five items of type T and returns the largest
   item in the array.(Because the size is fixed,it can be hardcoded into the loop instead of being passed as an rgument)
   . Test it in a program that uses the function with an array of five int value({1, 2, 3, 4 ,5}) and an array of five
   double values{1.1, 2.0, 3.0, 4.0, 5.5}.

A sample run might look like this:.

``` log
Max int = 5
Max double = 5.1
```