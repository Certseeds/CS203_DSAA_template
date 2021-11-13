<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-07 09:49:44
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-24 20:40:13
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# Assignment3

### 1. Dodging bullets

#### Description:

Cirno is addicted to playing STG. (A kind of game that player need to control a character dodging(闪避) bullets). Now
consider the screen is a n*m grid. There will be k bullets on the screen which will fly in straight line. A point that
won’t be touched by all the bullets is a safe point. Now Cirno need you to write a program to tell there are how many
safe points. (start point of bullets is not safe point).

Input:
The first line has 3 integer n, m and k, represent the size of screen and the number of bullets.Then there will be
follows by k lines.Each line has 4 integers,first two integers represent the start point of this bullet and the last two
integers is the direction of this bullet invect or form. The directions have only 8 possibility: (0,1), (1,1), (1,0), (
1,-1), (0,-1), (- 1,-1), (-1,0) and (-1,1).

Output:
Print one integer represent the number of safe points.

Sample:

``` log
Input:
   3 4 5
   1 1 1 -1
   1 1 -1 1
   0 3 1 0
   0 2 1 0
   0 0 -1 -1
Output:
   3
```

### 2. Spiral array

#### Description:

Given two integers m, n, generate a m*n matrix filled with elements from 1 to m*n in anticlockwise spiral order,
starting from the top right corner.

Input:

> The input is two integers m, n.

Output:

> The m*n spiral matrix as the sample. Sample Input and Output:

Sample:

``` log
Input:
   4 4
Output:
   4 3 2 1
   5 14 13 12
   6 15 16 11
   7 8 9 10
```

``` log
Input:
   5 3
Output:
   3 2 1
   4 13 12
   5 14 11
   6 15 10
   7 8 9
```

### 3. Download (with wget)

http://www.unicode.org/Public/8.0.0/ucd/Blocks.txt

1. Define a suitable structure to load all this in an array (size 300 is big enough)
2. Write a function to search this array when provided with a Unicode value, and a small test program. You are provided
   with code that does Unicode/UTF-8 conversions Read a file from the standard input - that means that your program will
   be called like this:

> ./your_program < name_of_file_to_analyze

Your program must display on the standard output the name of the block to which most characters belong (there may be
characters from different blocks)