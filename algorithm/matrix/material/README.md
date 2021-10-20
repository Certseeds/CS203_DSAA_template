<!--
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-07 10:09:50
 * @LastEditTime: 2020-05-11 22:55:06
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# project-matrix

## Building a library for matrix computation

1. Matrix is an important concept introduced in linear algebra. Matrix calculation is widely used in many practical applications, 
such as image processing and machine learning. Programmers can indeed use many different existing libraries, and in certain cases, 
programmers are required to design their own matrix calculation libraries for specific implementations.
This project will build a new library (do not attempt to directly copy codes from other existing library)
that can perform the following operations on the matrix:
1.  It supports all matrix sizes, from small fixed-size matrices to arbitrarily large dense matrices, 
    and even sparse matrices (Add: try to use efficient ways to store the sparse matrices).
2.  It supports all standard numeric types, including std::complex, integers, and is easily extensible to custom numeric types.
3.  It supports matrix and vector arithmetic, including addition, subtraction, scalar multiplication, scalar division,
     transposition, conjugation, element-wise multiplication, matrix-matrix multiplication, matrix-vector multiplication, 
     dot product and cross product.
4.  It supports basic arithmetic reduction operations, including finding the maximum value, finding the minimum value, 
    summing all items, calculating the average value (all supporting axis-specific and all items).
5.  It supports computing eigenvalues and eigenvectors, calculating traces, computing inverse and computing determinant.
6.  It supports the operations of reshape and slicing.
7.  It supports convolutional operations of two matrices.
8.  It supports to transfer the matrix from OpenCV to the matrix of this library and vice versa.
9.  It should process likely exceptions as much as possible.

1. 支持所有矩阵大小,(Bonus: 稀疏矩阵).

2. 支持所有标准数字类型,int,double,complex and 自定义类型.

3. 支持矩阵和矢量算数,支持+,-,*,/(前面四个指的是基本数据类型),转置,共轭,逐元素乘法(A:m_n,B:m_n,结果m_n),
矩阵-矩阵的乘法(A:m_n,B:n_p,结果m_p),矩阵-向量的乘法(A:m_n,B:n_1,结果m_1,前一个的特化),
点乘(要求两者大小一致,似乎就是阿达嘛乘积),叉乘(似乎就是matrix-matrix的普通乘法).

4. 基本的算数规约运算,包括查找最大值,最小值,求和,计算平均值.(还要对可以指定行,列,或者整个矩阵).

5. 可以计算特征向量,特征值,Trace(迹),逆以及行列式.

6. 支持reshape(重整),slice(切片).(此处参考numpy).

7. 支持卷积.

8. 支持和opencv的矩阵之间的双向转换(重点是搞明白opencv里面奇怪的数据类型).

9.  尽可能处理异常.

PS: This 2021-spring's project-Matrix is absolutely same with this one.