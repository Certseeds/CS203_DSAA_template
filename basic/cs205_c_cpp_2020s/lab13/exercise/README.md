<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 11:45:12
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:38:36
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04),C++17, Cmake 3.16.6.

# Lab13 Exercise: 2020_0514

## Code & Result

### Code

1. CStereoShape.h

``` cpp
#ifndef CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
#define CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
class CStereoShape {
private:
    inline static int numberOfObject = 0;
    // or static int numberOfObject;
    // && int CStereoShape::numberOfObject = 0;
public:
    CStereoShape();
    ~CStereoShape();
    virtual double GetArea();
    virtual double GetVolume();
    virtual void Show();
    int GetNumOfObject();
};
#endif //CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
```

2. CStereoShape.cpp

``` cpp
#include "CStereoShape_lab13_01.h"
#include <iostream>
CStereoShape::CStereoShape() {
    numberOfObject++;
}
double CStereoShape::GetArea() {
    std::cout << "CStereoShape::GetArea()" << std::endl;
    return 0.0;
}
double CStereoShape::GetVolume() {
    std::cout << "CStereoShape::GetVolume()" << std::endl;
    return 0.0;
}
void CStereoShape::Show() {
    std::cout << "CStereoShape::Show()" << std::endl;
}
int CStereoShape::GetNumOfObject() {
    return  CStereoShape::numberOfObject;
}
CStereoShape::~CStereoShape() {
    numberOfObject--;
}
```

3. CCube.h

``` cpp
#ifndef CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
#define CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H

#include "./CStereoShape_lab13_01.h"

class CCube : public CStereoShape {
private:
    double length;
    double width;
    double height;
public:
    CCube();
    CCube(double len, double wid, double heig);
    CCube(const CCube &CC);
    double GetArea() override;
    double GetVolume() override;
    void Show() override;
};
#endif //CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
```

4. CCube.cpp

``` cpp
#include "./CCube_lab13_02.h"
#include <iostream>
CCube::CCube() : CCube(0, 0, 0) {}
CCube::CCube(double len, double wid, double heig) {
    this->length = len;
    this->width = wid;
    this->height = heig;
}
CCube::CCube(const CCube &CC) {
    this->length = CC.length;
    this->width = CC.width;
    this->height = CC.height;
}
double CCube::GetArea() {
    return this->length * this->width * this->height;
}
double CCube::GetVolume() {
    return 2 * this->length * this->width \
 + 2 * this->width * this->height \
 + 2 * this->length * this->height;
}
void CCube::Show() {
    std::cout << "length is " << this->length << "\n";
    std::cout << "width is " << this->width << "\n";
    std::cout << "height is " << this->height << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
```

5. CSphere.h

``` cpp
#ifndef CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H
#define CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H
#include "CStereoShape_lab13_01.h"
class CSphere : public CStereoShape {
private:
    double radius;
public:
    CSphere();
    CSphere(double rad);
    // 拷贝构造函数 Copy Constructor
    CSphere(const CSphere &CC);
    double GetArea() override;
    double GetVolume() override;
    void Show() override;
};
#endif //CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H
```

6. CSphere.cpp

``` cpp
#include "./CSphere_lab13_03.h"
#include <cmath>
#include <iostream>

CSphere::CSphere() : CSphere(0) {}
CSphere::CSphere(double rad) {
    this->radius = rad;
}
CSphere::CSphere(const CSphere &CC) {
    this->radius = CC.radius;
}
double CSphere::GetArea() {
    return 4.0f * M_PI * pow(this->radius, 2);
}
double CSphere::GetVolume() {
    return 4.0f / 3.0f * M_PI * pow(this->radius, 3);
}
void CSphere::Show() {
    std::cout << "radius is " << this->radius << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
```

7. lab13_04.cpp

``` cpp
#include "./CStereoShape_lab13_01.h"
#include "./CCube_lab13_02.h"
#include "./CSphere_lab13_03.h"
#include <iostream>
int main() {
    CCube a_cube(4.0f, 5.0f, 6.0f);
    CSphere c_sphere(7.9f);
    CStereoShape *p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    std::cout << p->GetNumOfObject();
    return 0;
}
```

8. Cmakelist.txt

``` cmake
cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab13_exercise LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
add_executable(${PROJECT_NAME}
        ./CStereoShape_lab13_01.cpp
        ./CCube_lab13_02.cpp
        ./CSphere_lab13_03.cpp
        ./lab13_04.cpp
        )
```

### Result

#### Test Case #1

``` log
Input:
    no input
Output:
    length is 4
    width is 5
    height is 6
    Area is 120
    Volumn is 148
    radius is 7.9
    Area is 784.267
    Volumn is 2065.24
    2
```

![picture_01](./lab13_01.png)