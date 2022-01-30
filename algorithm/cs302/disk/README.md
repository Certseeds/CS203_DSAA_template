# <del>Lab10</del> Disk Scheduling

## Problem Description:

The structure of disk is shown as follows, the track Number

start from outer to inner (the outset track is Number-0 track).

And the default moving direction of head is from inner to outer.

Complete C-LOOK algorithms. Return the visiting sequence of tracks and calculate the total moving distance.

磁盘结构如下图所示(此处无图), 磁道计数自外向内增大,最外侧为0. 磁头默认移动方向自内向外.

请实现C-LOOK算法, 返回磁头的visit顺序,计算综合移动距离.

## IO:

### Input:

First Line: S(0<=S<M), M(0<M<=65536) and N <del>(0>n>M)</del> (WTF does it means?)

S represents the position of beginning track.

M represents the total number of tracks in disk.

N represents the number of scheduling requests.

Second Line: N integers  
Represent the track number that needs requesting.

S代表初始磁道位置, M代表总磁道数,N代表调度算法请求数

接下来的N个数字代表每个请求所在的磁道数

#### Input Example:

50 200 8 95 180 34 119 11 123 62 64

### Output:

First Line: the visiting sequence of tracks

Second Line: the total moving distance

第一行输出visit顺序(数字代表磁道)

第二行输出总移动距离

#### Output Example:

50 34 11 180 123 119 95 64 62  
326
