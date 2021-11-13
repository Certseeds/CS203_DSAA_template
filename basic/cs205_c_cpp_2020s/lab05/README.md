<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-08 09:03:02
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 08:31:14
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab05

1. Write a program that asks the user to type in numbers.After each entry,the program should report the cumulative sum
   of the entries to date.The program should terminate when the user enters 0.

Output:

``` log
    Enter integer number : 1
    The cumulative sum of the entries to data is :1
    Enter integer number : 2
    The cumulative sum of the entries to data is :3
    Enter integer number : 3
    The cumulative sum of the entries to data is :6
    Enter integer number : 4
    The cumulative sum of the entries to data is :10
    Enter integer number : 5
    The cumulative sum of the entries to data is :15
    Enter integer number : 0
    The cumulative sum of the entries to data is :15
```

2. Write a program that uses an array of char and a loop to read one word at a time until the word done is entered.The
   program should then report the number of words entered (not counting done ).A sample run could look like this:

``` log
Input:
    Happy Birthday for you done for sure.
Output:
    You entered a total of 4 words.
```

You should include the `cstring` header file and use the `strcmp()` function to make the comparison test.

3. Write a program to to Generate Fibonacci Sequence Up to a Certain Number .Each number fibonacci sequence is the sum
   of the two preceding ones,starting from 0 and 1. That is:

$$fibs[0]:0,fibs[1]:1,while n>1,finbs[n]=fibs[n-1]+fibs[n-2]$$

Please write three programs using `while`, `for` and `do...while` statements respectively.

A sample run could look like this:

``` log
Input:
    1000
Output:
    Fibonacci Series:
    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
```

4. Write a program that will print the following pattern

``` log
    1******
    12*****
    123****
    1234***
    12345**
    123456*
    1234567
```