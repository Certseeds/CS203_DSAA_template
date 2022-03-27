<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-07 10:18:43
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:59:05
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: MSVC2019.

# Lab02 Exercise Report

## E1 Code & Result

### Code

``` cpp
#include <iostream>
#include <vector>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int sub_main_02_01();
#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02
int main() {
    const int32_t will_return = sub_main_02_01();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_03
int sub_main_02_01() {
    cout << "Result:" << endl;
    printf("%-2s%-s %-2s%s  %s%-5s%s\n", "x", "value",
           "y", "value", "Expressions", " ", "Result");
    //cout << "x value y value  Expressions   Result"<<endl;
    const int x = 10;
    const int y = 5;
    char str1[5][4] = {"y+3", "y-2", "y*5", "x/y", "x%y"};
    vector<int> str2 = {y + 3, y - 2, y * 5, x / y, x % y};
    for (int i = 0; i < 5; i++) {
        printf("%-3d|%4s%-2d|%6s", x, " ", y, " ");
        printf("x=%-14s|x=%-4d", str1[i], str2[i]);
        cout << endl;
    }
    return 0;
}
int main_lab02_01() {
    cout << "Result:" << endl;
    printf("%-2s%-s %-2s%s  %s%-5s%s\n", "x", "value",
           "y", "value", "Expressions", " ", "Result");
    //cout << "x value y value  Expressions   Result"<<endl;
    const int x = 10;
    const int y = 5;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    for (auto i : vec1) {
        cout << i << endl;
    }
    char str1[5][4] = {"y+3", "y-2", "y*5", "x/y", "x%y"};
    vector<int> str2 = {y + 3, y - 2, y * 5, x / y, x % y};
    for (int i = 0; i < 5; i++) {
        printf("%-3d|%4s%-2d|%6s", x, " ", y, " ");
        printf("x=%-14s|x=%-4d", str1[i], str2[i]);
        cout << endl;
    }
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    no need input 
Output: 
    five lines of calculate results
```

![picture_01](./lab02_01.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
constexpr int32_t hours_number = 24;
constexpr int32_t minute_number = 60;
constexpr int32_t second_number = 60;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int sub_main_02_02();
#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02
int main() {
    const int32_t will_return = sub_main_02_02();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_02
int sub_main_02_02() {
    long long seconds = 0;
    while (0 == seconds || cin.fail()) {
        cout << "Enter the number of Seconds:";
        cin >> seconds;
        if (0 != seconds) {
            cout << seconds;
        }
        cin.clear();
        cin.ignore(INT8_MAX, '\n');
        cin.sync();
    }
    long long days = seconds / (hours_number * minute_number * second_number);
    seconds = seconds % (hours_number * minute_number * second_number);
    long long hours = seconds / (minute_number * second_number);
    seconds %= (minute_number * second_number);
    long long minutes = seconds / second_number;
    seconds %= second_number;
    cout << " " << "seconds = " << days << " days, " << hours;
    cout << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    31600000
Output:
    31600000 seconds = 365 days, 17 hours, 46minutes, 40seconds
```

![picture_02](./lab02_02.png)

``` log
Input: 
    abc
    365000
Output: 
    enter the numbers of seconds
    365000 seconds = 4 days, 5 hours, 23 minutes, 20seconds
```

![picture_03](./lab02_03.png)

## E3 Code & Result

### Code

``` cpp
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int sub_main_02_03();

#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02
int main() {
    const int32_t will_return = sub_main_02_03();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !UNIT_TESTING_LAB_03

int sub_main_02_03() {
    char ch = '0';
    int in = -1;
    float fl = 0;
    cout << " Please Enter a Character : ";
    cin >> ch;
    cout << " Please Enter an Integer Value : ";
    cin >> in;
    cout << " Please Enter Float Value : ";
    cin >> fl;
    cout << endl;
    cout << " The variables you entered were : \n";
    cout << " The Character Value that you Entered is : ";
    printf("%c\n", ch);
    cout << " The Integer Value that you Entered is : ";
    printf("%d\n", in);
    cout << " The Float Value that you Entered is : ";
    printf("%f\n", fl);
    return 0;
}
```

### Result

#### Test Case #1

``` log
Input: 
    Z,1926,8.17
Output:
    Z,1926,8.17000008(because the precision is set to 8)
```

![picture_04](./lab02_04.png)

``` log
Input: 
    Z,1926.0817,null
Output:
    Z,1926,0.0817
```

![picture_05](./lab02_05.png)
