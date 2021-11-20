<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 10:57:28
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:37:28
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04),C++17, Cmake 3.16.6.

# Lab11 Exercise: 2020_0430

## E1 Code & Result

### Code

1. lab11_01.cpp

``` cpp
#include <iostream>
#include "./CandyBar.h"
int main(){
    CandyBar cb; // 构造函数 无参
    cb.setCandyBar();
    cb.showCandyBar();
    CandyBar cb2("Zhanche",19.2f,11); // 构造函数 1
    CandyBar cb3(std::string("Yinzhe"),11.4f,19); // 构造函数 2
    CandyBar cb4(cb); // 拷贝构造函数
    CandyBar cb5 = std::move(cb4); // 移动构造函数
    CandyBar cb6 = cb5; // 拷贝构造函数
    CandyBar cb7 = CandyBar("Diao DIao ren",81.0f,9); // 默认构造函数
    CandyBar cb8 = std::move(CandyBar("Sum",48.0f,4)); // 移动构造函数
    CandyBar cb9 = get_a_candyBar();
    CandyBar cb10;
    cb10 = std::move(cb9); // 移动赋值运算符
    CandyBar cb11; // 构造函数 无参
    cb11 = get_a_candyBar(); // 构造函数 1,然后移动赋值运算符.
    // cb11 = cb10; can not do copy 赋值
    return 0;
}
```

2. CandyBar.h

``` cpp
#ifndef CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
#define CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
#include <iostream>
class CandyBar {
private:
    std::string name;
    double weight;
    int calories;
public:
    explicit CandyBar();
    explicit CandyBar(const char *n, double w, int32_t cal);
    explicit CandyBar(const std::string &n, double w, int32_t cal);
    // 拷贝构造函数 Copy Constructor
    CandyBar(const CandyBar &s);
    // 移动构造函数
    CandyBar(CandyBar &&s);
    // 拷贝赋值运算符 Copy Assignment operator
    CandyBar &operator=(const CandyBar &) = delete;
    // 移动赋值运算符 Move Assignment operator
    CandyBar &operator=(CandyBar &&data);
    int32_t setCandyBar();
    void showCandyBar();
};
CandyBar get_a_candyBar();
#endif //CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
```

3. CandyBar.cpp

``` cpp
#include "./CandyBar.h"
std::string trim(std::string str);
CandyBar::CandyBar() : name("\0"), weight(-1.0f), calories(-1) {
}
CandyBar::CandyBar(const char *n, double w, int32_t cal) : weight(w), calories(cal) {
    this->name = std::string(n);
    // use string's  ?
}
CandyBar::CandyBar(const std::string &n, double w, int32_t cal) : weight(w), calories(cal) {
    this->name = n;
    // use string's 拷贝构造函数
}
CandyBar::CandyBar(const CandyBar &s) : weight(s.weight), calories(s.calories) {
    this->name = s.name;
    // use string's 拷贝构造函数
}
CandyBar::CandyBar(CandyBar &&s) : weight(s.weight), calories(s.calories) {
    if (this != &s) {
        this->name = std::move(s.name);
        s.weight = -1.0f;
        s.calories = -1;
    }
}
CandyBar &CandyBar::operator=(CandyBar &&data) {
    if (this != &data) {
        this->weight = data.weight;
        this->calories = data.calories;
        this->name = std::move(data.name);
        data.weight = -1.0f;
        data.calories = -1;
    }
    return *this;
}
int32_t CandyBar::setCandyBar() {
    std::cout << "Enter brand name of a Candy bar: ";
    std::getline(std::cin, this->name);
    this->name = trim(this->name);
    std::cout << "Enter weight name of the candy bar: ";
    std::cin >> this->weight;
    std::cout << "Enter calories (an integer value) in the candy bar: ";
    std::cin >> this->calories;
    return 0;
}
void CandyBar::showCandyBar() {
    std::cout << "Brand: " << this->name << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Calorie: " << this->calories << std::endl;
}
CandyBar get_a_candyBar() {
    CandyBar will_return("123", 45.0f, 7);
    return will_return;
}
std::string trim(std::string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
```

### Result

#### Test Case #1

``` log
Input:
    new
    4.5
    230    
Output:
    Brand: new
    Weight: 4.5
    Calorie: 230
```

![picture_01](./lab11_01.png)

#### Test Case #2

``` log
Input:
      Black CHock   
    22.04
    28  
Output:
    Brand: Black CHock
    Weight: 22.04
    Calorie: 28
```

![picture_02](./lab11_02.png)

## E2 Code & Result

### Code

1. lab11_02.cpp

``` cpp
#include <iostream>
#include "./Rectangle.h"
int main(){
    std::cout << "Rectangle 1" << std::endl;
    Rectangle r1(4,40);
    r1.display();
    std::cout << "Rectangle 2" << std::endl;
    Rectangle r2(3.5,35.9);
    r2.display();
    return 0;
}
```

2. Rectangle.h

``` cpp
#ifndef CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
#define CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
class Rectangle {
private:
    double width = 1;
    double height = 1;
public:
    Rectangle();
    Rectangle(double w,double h);
    double getArea();
    double getPerimeter();
    void display();
};
#endif //CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
```

3. Rectangle.cpp

``` cpp
#include "./Rectangle.h"
#include <iostream>
#include <iomanip>
Rectangle::Rectangle() {}
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
double Rectangle::getArea() {
    return this->width * this->height;
}
double Rectangle::getPerimeter() {
    return 2 * (this->width + this->height);
}
void Rectangle::display() {
    std::cout << "-------------" << std::endl;
    std::cout << "Width:      " << std::setiosflags(std::ios::left) 
    << this->width << std::endl;
    std::cout << "Height:     " << std::setiosflags(std::ios::left) 
    << this->height << std::endl;
    std::cout << "Area:       " << std::setiosflags(std::ios::left) 
    << this->getArea() << std::endl;
    std::cout << "Perimeter:  " << std::setiosflags(std::ios::left) 
    << this->getPerimeter() << std::endl;
}
```

### Result

#### Test Case #1:

``` log
Input: 
    No input.
Output:
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
    Area:       125.65
    Perimeter:  78.8
```

![picture_03](./lab11_03.png)