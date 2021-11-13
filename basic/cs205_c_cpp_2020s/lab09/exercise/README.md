<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-18 10:57:28
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:36:41
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04),C++17, Make 4.1.

# Lab09 Exercise: 2020_0416

## E1 Code & Result

### Code

1. fun.h

``` cpp
#ifndef CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
#define CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
// copy with reference notation
void CopyArray(double(&target)[5], double (&source)[5]);
// copy with pointer notation
void CopyArray(double *target, const double *source, int len);
// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end);
//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len);
#endif //CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
```

2. fun.cpp

``` cpp
#include "fun.h"
#include <iostream>
#include <iomanip>
void CopyArray(double(&target)[5], double (&source)[5]) {
    for (int i = 0; i < 5; ++i) {
        target[i] = source[i];
    }
}
// copy with pointer notation
void CopyArray(double *target, const double *source, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}
// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end) {
    for (int i = 0; i <= (source_end - source_start); ++i) {
        target[i] = source_start[i];
    }
}
//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len) {
    const int interval = 20;
    std::cout << 
    std::setw(interval) << "target1|" << 
    std::setw(interval)<< "target2|" << 
    std::setw(interval) << "target3|" << std::endl;
    for (int i = 0; i < len; ++i) {
        std::cout << 
        std::setw(interval - 1) << target1[i] << "|" << 
        std::setw(interval - 1)<< target2[i] << "|" << 
        std::setw(interval - 1) << target3[i] << "|" << std::endl;
    }
}
```

3. main.cpp

``` cpp
#include "fun.h"
int main() {
    double source[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double target1[5];
    double *target2 = new double[5];
    double *target3 = new double[5];
    CopyArray(target1, source);
    CopyArray(target2, source, 5);
    CopyArray(target3, source, &source[4]);
    PrintArray((double *) (&target1), target2, target3, 5);
    delete[] target2;
    delete[] target3;
    return 0;
}
```

4. Makefile_1

``` Makefile
CC = g++
TARGET = main1.out
OBJ = main.o fun.o
INCLUDE = fun.h
CFLAGS= -c -Wall -Wextra
$(TARGET): $(OBJ)
	$(CC) $^ -o $@
%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@
# make -f Makefile_1
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
#  make -f Makefile_1 clean
```

### Result

#### Test Case #1:

``` log
Input:
    No input
Output:
            target1|            target2|            target3|
                1.1|                1.1|                1.1|
                2.2|                2.2|                2.2|
                3.3|                3.3|                3.3|
                4.4|                4.4|                4.4|
                5.5|                5.5|                5.5|
```

![picture_01](./lab09_01.png)

#### Test Case #2:Clean

![picture_01_2](./lab09_01_2.png)

## E2 Code & Result

### Code

1. CandyBar.h

``` cpp
#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H
#include <iostream>
const int Len = 40;
struct CandyBar {
    char brand[Len];
    double weight;
    int calorie;
};
// prompt the user to enter each of the preceding items of information and
// store them in the CandyBar structure
int setCandyBar(CandyBar &snack);
void showCandyBar(const CandyBar &snack);
#endif //EXC_CANDYBAR_H
```

2. candybar.cpp

``` cpp
#include "CandyBar.h"
#include <iostream>
#include <cstring>
int setCandyBar(CandyBar &snack) {
    while ((getchar()) != '\n');
    char name[40];
    double weight;
    int calorie;
    std::cout << "Enter brand name of a Candy bar: ";
    std::cin.getline(name, Len);
    if (0 == std::strlen(name)) {
        std::cout << std::endl;
        std::cout << "empty name detected!" << std::endl;
        return -1;
    }
    std::cout << "Enter weight name of the candy bar: ";
    std::cin >> weight;
    std::cout << "Enter calories (an integer value) in the candy bar: ";
    std::cin >> calorie;
    std::memcpy(snack.brand, name, Len);
    snack.weight = weight;
    snack.calorie = calorie;
    return 0;
}
void showCandyBar(const CandyBar &snack) {
    std::cout << "Brand: " << snack.brand << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "Calorie: " << snack.calorie << std::endl;
}
```

3. main2.cpp

``` cpp
#include "CandyBar.h"
#include <iostream>
#include <string>
int main() {
    CandyBar *cb = new CandyBar[5];
    uint32_t number;
    std::cout << "Please enter the number of candybar:" << std::endl;
    std::cin >> number;
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        if (0 != setCandyBar(cb[i])) {
            delete[] cb;
            return 0;
        }
    }
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        showCandyBar(cb[i]);
    }
    delete[] cb;
    return 0;
}
```

4. Makefile_2

``` Makefile
CC = g++
TARGET = main2.out
OBJ = main2.o candybar.o
INCLUDE = CandyBar.h
CFLAGS= -c -Wall -Wextra
$(TARGET): $(OBJ)
	$(CC) $^ -o $@
%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@
# make -f Makefile_2
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
#  make -f Makefile_2 clean
```

### Result

#### Test Case #1:

``` log
Input: 
    new
    1.1
    2
    old
    2.2
    3
    ceshi
    3.3
    4
    test
    4.4
    5
    final
    5.5
    6    
Output:
    CandyBar[0]
    Brand: new
    Weight: 1.1
    Calorie: 2
    CandyBar[1]
    Brand: old
    Weight: 2.2
    Calorie: 3
    CandyBar[2]
    Brand: ceshi
    Weight: 3.3
    Calorie: 4
    CandyBar[3]
    Brand: test
    Weight: 4.4
    Calorie: 5
    CandyBar[4]
    Brand: final
    Weight: 5.5
    Calorie: 6
```

![picture_02](./lab09_02.png)

#### Test Case #2:

``` log
Input: 
    new
    2.2
    3
    old
    4.54 98
Output:
    empty name detected!
```

![picture_03](./lab09_03.png)

#### Test Case #3:Clean

![picture_04](./lab09_04.png)