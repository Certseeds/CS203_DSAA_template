<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-09 09:10:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-18 21:52:30
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_MIDTERM

1. We do not recommend that you use any codes in books or websites for our midterm exam. While, due to current special
   conditions, you can reuse the codes from somewhere. However, if you really cannot implement these codes, and have
   searched for codes that can be used, you must provide the source information of these codes. As you reuse some codes,
   your possible highest score will be twothirds of the original score. Otherwise, if you copy some code without any
   explanation, it will be considered as plagiarism and the behavior will be definitely reported to the university.
2. Please USE C language, which we have learned, to implement all codes but the objects from C/C++ standard can be used,
   such as `cout` `cin`.
3. Each file contains the codes of one question and you need to finish any three questions.
4. You are allowed to submit your answers up to three times.

### Question 1: Word Count – Mingji

Jony J, a famous rapper, is the rap supervisor of YOUTH WITH YOU. He wants to know how good the lyrics written by his
students. He believes that if the frequency of the most frequent word is greater than or equals to k, the lyrics is
good. Given a C-style string, and an integer k, you are required to write a function to evaluate whether the lyrics is
good or not.

Rules:
Each word in string is separated by one black space.  
Each word only has lowercase English letters.  
There is no other type of character in the string.  
The length of string is greater than 1. The string will never be null.  
The integer k is greater than 1 and smaller than the maximum value of integer.  
You are allowed to use anything in C standard.  
You can define any data structure or function outside the evaluate() function.  
The function should return 1 if the lyrics is good.  
The function should return 0 if the lyrics is not good.  
The function should finish in finite time. So it is OK if the time complexity is high.  
`int evaluate(const char* s, const int k) {}`
Example:

evaluate("jiu dang shi yi chang meng xing le hen jiu hai shi hen gan dong", 2) should return 1  
evaluate("dan huang de chang qun peng song de tou fa", 4) should return 0

### Questions 2: Basic calculation of Matrix – Liu Zhu

Create a structure of Matrix. And, you are required to complete the following functions:

1. Read the matrices from the files
2. Implement addition and subtraction of Matrix.
3. Implement matrix multiplication and element-wise multiplication (Check possibility first ).
4. Check whether the matrix a square matrix. If yes, print the determinant and trace.

Note: You need to read the test cases - Matrix1 and Matrix2 - from Matrix1.txt and Matrix2.txt. But you must handle the
necessary exceptions (Like shape matching, square-needed). And the size should not be fixed as that in the file and we
will test using different sizes of matrices. (That means only getting a right result of the case we provided can NOT get
full mark.)

Output Reference:

``` log
The first matrix is:
1 3 2
2 4 5
0 2 1
The second matrix is:
2 1 4
3 2 1
5 3 2
The addition of the two matrices is:
3 4 6
5 6 6
5 5 3
The subtraction of the two matrices is:
-1 2 -2
-1 2 4
-5 -1 -1
The matrix multiplication of the two matrices is:
21 13 11
41 25 22
11 7 4
The element-wise multiplication of the two matrices is:
2 3 8
6 8 5
0 6 2
The first matrix is square!
The determinant of the first matrix is: -4.0
The trace of the first matrix is: 6
The second matrix is square!
The determinant of the first matrix is: -3.0
The trace of the first matrix is: 6
```

### Questions 3: Book lending system -- Zongwei

The book lending system in the ABC University is going to be updated. The managers ask you, a student from CSE
Department, for help.

1. For each student who can borrow books, the following information should be recorded:
1. The name of the student;
2. The student ID of the student;
3. The number of books borrowed by this student (unreturned yet);
4. Days each book has been borrowed.

Design a structure that can hold this information.  
(e.g.

``` cpp
Student name: Tom
Student id:11912345
Number of book: 4
Borrowing days: 15, 27, 33, 67
```

)

2. The cost of borrowing books depends on the borrowing days. The rules of borrowing are as follows:
1. If borrowing days <=30: Free;
2. If borrowing days>30 and <=60: This part (30-60 days) costs 0.5 RMB/day;
3. If borrowing days>60: This part (>60 days) costs 1 RMB/day.

Please write a function that can calculate the total cost of a student (if this student returns all the book today).

Example:

``` log
Please input the name of student: Tom
Please input the student ID of this student: 12345678
Number of books this student borrowed: 4
The borrowing days are: 15 27 33 67
```

Output:
If this student returns all the books today, he should pay: 23.5 RMB.

### Questions 4: Encoding and decoding a matrix – Xu Shuo

Given a matrix $𝐴$ of size $𝑚 × 𝑛$, the element is either 1 or 0 and the upper left is fixed to 1, such as  
$$ A= \left[
\begin{matrix} 1 & 1 & 1 & 0\\ 0 & 0 & 0 & 1\\ 1 & 1 & 1 & 1\\ 1 & 0 & 0 & 0 \end{matrix} \right] \tag{4} $$ By row
expansion, it can be expressed as: 𝐴 = [1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0]. Then, we can count the adjacent repeating
digits to represent the matrix as “three ones, four zeros, six ones and three zeros”. Furthermore, we can simply
represent the matrix using a string 𝐵 = "4,4,3,4,6,3", in which the first two numbers are the numbers of rows and
columns, respectively.

You are required to implement the two following algorithms:

1. Given a matrix $𝐴$ of size $𝑚 × 𝑛$, design a function `encode()` to obtain the string $𝐵$.
2. Design a function `decode()` to decode the string 𝐵𝐵 into the original matrix 𝐴.