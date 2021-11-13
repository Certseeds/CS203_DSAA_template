<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-09 09:06:39
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 09:09:15
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab15

Write a function `calculateAverage()` which takes four int arguments which are marks for four courses in the semester
and returns their average as a float.

The `calculateAverage()` function should take only valid range for marks which is between 0 - 100. If the marks are out
of range throw an OutOfRangeException - define this exception as a class.

Invoke the `calculateAverage()` function in main function and get the following inputs and outputs:

``` log
    Please enter marks for 4 courses:60 80 90 100
    The avarage of the four courses is 82.5
```

``` log
    Please enter marks for 4 courses:90 -80 70 80
    The parameter1 is -80 which out of range(0-100)
```

``` log
    Please enter marks for 4 courses:80 90 110 80
    The parameter1 is 110 which out of range(0-100)
```