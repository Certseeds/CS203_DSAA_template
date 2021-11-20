<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-19 18:25:17
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-19 22:33:30
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->
**Environment**:MSVC

# Lab05 Exercise Report : 2020_0319

## E1 Code & Result

### Code

``` cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int32_t sub_main_05_01();
#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_
int main() {
    const int32_t will_return = sub_main_05_01();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !_UNIT_TESTING_LAB_05_
int32_t sub_main_05_01() {
    int32_t value = 0;
    int32_t sum = 0;
    do {
        cout << "Enter integer number : ";
        cin >> value;
        cin.sync();
        sum += value;
        cout << "The cumulative sum of the entries to data is :" << sum << endl;
    } while (0 != value);
    return 0;
}
```

### Result

#### Test Case #1:

```
Input: 
    19
    26
    08
    17
    1716
Output:
    Enter integer number : 19
    The cumulative sum of the entries to data is :19
    Enter integer number : 26
    The cumulative sum of the entries to data is :45
    Enter integer number : 08
    The cumulative sum of the entries to data is :53
    Enter integer number : 17
    The cumulative sum of the entries to data is :70
    Enter integer number : 1716
    The cumulative sum of the entries to data is :1786
    Enter integer number : 0
    The cumulative sum of the entries to data is :1786
```

![picture_01](./lab05_01.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>
#include<cstring>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int32_t sub_main_05_02();
#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_
int main() {
    const int32_t will_return = sub_main_05_02();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !_UNIT_TESTING_LAB_05_
const int lab05_02_length = 1024;
const char done[] = "done";
int32_t sub_main_05_02() {
    char buffer[lab05_02_length+1];
    memset(buffer, '\0', (lab05_02_length+1) * sizeof(char));
    cout << "Entry words (to stop, type the word done):" << endl;
    uint32_t count = 0;
    while (true) {
        bool get_out = false;
        cin.get(buffer, lab05_02_length);
        while ((getchar()) != '\n');
        vector<char*> strings = { buffer };
        for (uint32_t x = 1; x < lab05_02_length; x++) {
            if (' ' == buffer[x]) {
                buffer[x] = '\0';
            }
            if ('\0' != buffer[x] && '\0' == buffer[x - 1]) {
                strings.push_back(buffer + x);
            }
        }
        for (auto i : strings) {
            if (0 == strcmp(done, i)) {
                get_out = true;
                break;
            }
            count++;
        }
        if (get_out) {
            break;
        }
        memset(buffer, '\0', lab05_02_length * sizeof(char));
    } 
    cout << "You entered a total of " << count << " words.";
    return 0;
}
```

### Result

#### Test Case #1:

``` log
Input: 
    in all sections, yuwen is the basic class
    it can import the basic language apower and other works.
    not at all! done
Output:
    You entered a total of 21 words.
```

![picture_02](./lab05_02.png)

## E3 Code & Result

### Code

``` cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int32_t sub_main_05_03();
int32_t while_fibonacci();
int32_t do_while_fibonacci();
int32_t for_fibonacci();
const char input_str[] = "Enter a positive number: ";
const char output_str[] = "Fibonacci Series: ";
const char illegal_str[] = "Please input positive";
#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_
int main() {
    const int32_t will_return = sub_main_05_03();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !_UNIT_TESTING_LAB_05_
int32_t sub_main_05_03() {
    while_fibonacci();
    do_while_fibonacci();
    for_fibonacci();
    return 0;
}
int32_t while_fibonacci() {
    int32_t range = 0;
    cout << input_str;
    cin >> range;
    while ((getchar()) != '\n');
    if (range <= 0) {
        cout << illegal_str << endl;
        return -1;
    }
    cout << output_str;
    int32_t zero = 0;
    int32_t one = 1;
    while (zero <= range) {
        cout << zero << " ";
        int32_t test = zero;
        zero = one;
        one += test;
    }
    cout << endl;
    return 0;
}
int32_t do_while_fibonacci() {
    int32_t range = 0;
    cout << input_str;
    cin >> range;
    while ((getchar()) != '\n');
    if (range <= 0) {
        cout << illegal_str << endl;
        return -1;
    }
    cout << output_str;
    int32_t zero = 0;
    int32_t one = 1;
    do {
        cout << zero << " ";
        int32_t test = zero;
        zero = one;
        one += test;
    } while (zero <= range);
    cout << endl;
    return 0;
}
int32_t for_fibonacci() {
    int32_t range = 0;
    cout << input_str;
    cin >> range;
    while ((getchar()) != '\n');
    if (range <= 0) {
        cout << illegal_str << endl;
        return -1;
    }
    cout << output_str;
    int32_t zero = 0;
    int32_t one = 1;
    for (; zero <= range;) {
        cout << zero << " ";
        int32_t test = zero;
        zero = one;
        one += test;
    }
    cout << endl;
    return 0;
}
```

### Result

#### Test Case #1:

```
Input:  
    19260
    817
    19980406
Output:  
    Fibonacci Series:  
    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584
    4181 6765 10946 17711
    Fibonacci Series:  
    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610
    Fibonacci Series:  
    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584
    4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040   
    1346269 2178309 3524578 5702887 9227465 14930352
```

![picture_03](./lab05_03.png)

#### Test Case #2: equal to range.

```
Input:  
    8
    13
    21
Output:  
    Enter a positive number: 8
    Fibonacci Series: 0 1 1 2 3 5 8
    Enter a positive number: 13
    Fibonacci Series: 0 1 1 2 3 5 8 13
    Enter a positive number: 21
    Fibonacci Series: 0 1 1 2 3 5 8 13 21
```

![picture_05](./lab05_05.png)

## E4 Code & Result

### Code

``` cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int32_t sub_main_05_04();
#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_
int main() {
    const int32_t will_return = sub_main_05_04();
    cin.get();
    cin.get();
    return will_return;
}
#endif // !_UNIT_TESTING_LAB_05_
int32_t sub_main_05_04() {
    const int32_t range = 7;
    char str[range+1];
    str[range] = '\0';
    for (int32_t i = 0; i < range; i++) {
        memset(str, '*', range * sizeof(char));
        for (int32_t j = 0; j < i+1;j++) {
            str[j] = ('1' + j);
        }
        cout << str << endl;
    }
    return 0;
}
```

### Result

#### Test Case #1:

```
Input:  
    input no need.
Output:
    1******
    12*****
    123****
    1234***
    12345**
    123456*
    1234567
```

![picture_04](./lab05_04.png)