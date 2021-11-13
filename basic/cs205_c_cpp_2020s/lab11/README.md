<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-09 08:41:57
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-30 23:06:48
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205_C_CPP_Lab11

1. Design a class named **CandyBar** to represent candybars,The class contains:

+ three data member variables.The first member holds the brand **name** of a candy bar.The second member holds the **
  weight** (which may have a fractional part) of the candy bar, and the third member holds **the number of calories** (
  an integer value) in the candy bar.
+ A method named `setCandyBar()` that should prompt the user to enter each of the items to set the corresponding member
  variables of the CandyBay .
+ A method named `showCandyBar()` that display the information of candybar. Write a test program that creates one **
  CandyBar** objects and display its information.A sample run might look like this:

``` log
Enter brand name of a Candy bar: new
Enter weight of the candy bar: 4.5
Enter calories (an integer value) in the candy bar: 230
Brand: new
Weight: 4.5
Calorie: 230
```

2. Design a class named Rectangle to represent a rectangle. The class contains:

+ Two double data fields named width and height that specify the width and height of the rectangle. The default values
  are 1 for both width and height .
+ A no-arg constructor that creates a default rectangle.
+ A constructor that creates a rectangle with the specified width and height .
+ A method named `getArea()` that returns the area of this rectangle.
+ A method named `getPerimeter()` that returns the perimeter.
+ A method named `display()` that print out the information of rectangle.

Write a test program that creates two Rectangle objects ,one with width 4 and height 40 , and the other with width 3.5
and height 35.9 . Display the width, height, area, and perimeter of each rectangle in this order.A sample run might look
like this:

``` log
    Rectangle 1
    -------------
    Width:      4
    Height:     40
    Area:       160
    Perimeter:  88
    Rectangle 2
    -------------
    Width:      3.5
    Height:     35.9
    Area:       125
    Perimeter:  78
```