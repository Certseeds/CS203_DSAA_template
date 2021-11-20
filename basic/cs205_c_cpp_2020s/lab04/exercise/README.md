<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-06 23:00:00
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-04-08 17:10:40
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# Lab04 Exercise: 2020_0312

## E1 Code & Result

### Code

1. pizza.hpp

``` cpp
#ifndef _LAB04_PIZZA_
#define _LAB04_PIZZA_
#include <iostream>
const int lab04_01_max_length = 1024;
class pizza {
public:
    char* name;
    double* diameter;
    double* weight;
    pizza() {
        name = new char[lab04_01_max_length];
        memset(name, '\0', lab04_01_max_length);
        diameter = new double;
        weight = new double;
    }
    pizza(char* n, double d, double w) {
        name = new char[lab04_01_max_length];
        diameter = new double;
        weight = new double;
        memset(name, '\0', lab04_01_max_length);
        memcpy(name, n, strlen(n) * sizeof(char));
        (*diameter) = d;
        (*weight) = w;
    }
    ~pizza() {
        delete[] name;
        delete diameter;
        delete weight;
    }
};
#endif //  _LAB04_PIZZA_
```

2. lab04_01.cpp

``` cpp
#include <iostream>
#include "./pizza.hpp"
using std::cin;
using std::cout;
using std::endl;
int sub_main_04_01();
#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04
int main() {
    const int32_t will_return = sub_main_04_01();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_04
int sub_main_04_01() {
    char* pizza_company = new char[lab04_01_max_length];
    memset(pizza_company, '\0', lab04_01_max_length);
    double diameter = 0.0f;
    double weight = 0.0f;
    cout << "Input name of the pizza : ";
    cin.getline(pizza_company, lab04_01_max_length);
    cout << "Input the diameter of pizza : ";
    cin >> diameter;
    cout << "Input the weight of pizza : ";
    cin >> weight;
    pizza* pz = new pizza(pizza_company, diameter, weight);
    cout << "Name of the pizza : ";
    cout << pz->name << endl;
    cout << "diameter of the pizza : ";
    cout << (*(pz->diameter)) << endl; 
    cout << "weight of the pizza : ";
    cout << (*(pz->weight)) << endl;
    delete pz;
    delete[] pizza_company;
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    "Firenze Pizza No."
    18
    189
Output:
    Name of the pizza : Firenze Pizza No.
    diameter of the pizza : 18
    weight of the pizza : 189
```

![picture_01](./lab04_01.png)

## E2 Code & Result

### Code

1. CandyBar.hpp

``` cpp
#ifndef _LAB04_CANDYBAR_
#define _LAB04_CANDYBAR_
#include <string>
const int lab04_02_maxrange = 1024;
struct CandyBar {
    char* name;
    double* weight;
    int* calories;
    CandyBar() {
        name = new char[lab04_02_maxrange];
        memset(name, '\0', lab04_02_maxrange);
        weight = new double;
        calories = new int;
    }
    CandyBar(char* n, double d, double w) {
        name = new char[lab04_02_maxrange];
        weight = new double;
        calories = new int;
        memset(name, '\0', lab04_02_maxrange);
        memcpy(name, n, strlen(n) * sizeof(char));
        (*weight) = d;
        (*calories) = w;
    }
    ~CandyBar() {
        delete[] name;
        delete weight;
        delete calories;
    }
};
#endif //!_LAB04_CANDYBAR_
```

2. lab04_02.cpp

``` cpp
#include <iostream>
#include"./CandyBar.hpp"
using std::cin;
using std::cout;
using std::endl;
int sub_main_04_02();
#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04
int main() {
    const int32_t will_return = sub_main_04_02();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_04
int sub_main_04_02() {
    char* name = new char[lab04_02_maxrange];
    double weight = 0;
    double calories = 0;
    CandyBar* cb_array = new CandyBar[3];
    for (int i = 0; i < 3; i++) {
        memset(name, '\0', lab04_02_maxrange);
        cout << "Input name of the CandyBar : ";
        cin.getline(name, lab04_02_maxrange);
        cout << "Input the weight of CandyBar : ";
        cin >> weight;
        cout << "Input the calories of CandyBar : ";
        cin >> calories;
        cin.get();
        memcpy(cb_array[i].name, name, strlen(name) * sizeof(char));
        (*cb_array[i].weight) = weight;
        (*cb_array[i].calories) = calories;
    }
    for (int i = 0; i < 3; i++) {
        cout << "name of the CandyBar " << i<< " : ";
        cout << cb_array[i].name << endl;
        cout << "weight of the CandyBar " << i << " : ";
        cout << (*cb_array[i].weight) << endl;
        cout << "the calories of CandyBar " << i << " : ";
        cout << (*cb_array[i].calories) << endl;
    }
    delete[] name;
    delete[] cb_array;
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    "No.1 amazing CandyBar"
    25
    200
    "Apple CanBar plus"
    20
    199
    "FaceCandy Twice"
    30
    250
Output:
    name of the CandyBar 0 : No.1 amazing CandyBar
    weight of the CandyBar 0 : 25
    the calories of CandyBar 0 : 200
    name of the CandyBar 1 : Apple CanBar plus
    weight of the CandyBar 1 : 20
    the calories of CandyBar 1 : 199
    name of the CandyBar 2 : FaceCandy Twice
    weight of the CandyBar 2 : 30
    the calories of CandyBar 2 : 250
```

![picture_02](./lab04_02.png)

## E3 Code & Result

### Code

``` cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int sub_main_04_03();
#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04
int main() {
    const int32_t will_return = sub_main_04_03();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_04
const int lab04_03_range = 5;
int sub_main_04_03() {
    int* five_array = new int[lab04_03_range];
    int* temp = five_array;
    memset(five_array, 0, lab04_03_range * sizeof(int));
    for (int i = 0; i < lab04_03_range; i++) {
        cout << "Input number " << i << " : ";
        cin >> (*temp);
        temp++;
        cin.get();
    }
    for (int i = 0; i < lab04_03_range; i++) {
        temp--;
        cout << "number " << i << " is : ";
        cout << (*temp)<< endl;
    }
    delete[] five_array;
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    19
    26
    8
    1
    7
Output:
    number 0 is : 7
    number 1 is : 1
    number 2 is : 8
    number 3 is : 26
    number 4 is : 19
```

![picture_03](./lab04_03.png)
