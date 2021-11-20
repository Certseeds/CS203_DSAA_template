<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-10 23:19:24
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:35:46
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

# Lab08 Exercise: 2020_0409

## E1 Code & Result

### Code

``` cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
const int32_t brand_length = 29;
struct CandyBar {
    char brand[brand_length + 1];
    double weight;
    int32_t calorie;
};
void set(CandyBar &cb);
void set(CandyBar *const cb);
void show(const CandyBar &cb);
void show(const CandyBar *cb);
int32_t main() {
    CandyBar cd1{};
    set(&cd1);
    show(&cd1);
    while ((getchar()) != '\n');
    set(cd1);
    show(cd1);
    return 0;
}
void set(CandyBar &cb) {
    cout << "Call the set function of passing by reference:" << endl;
    char brand_input[brand_length * 10 + 1];
    double weight_input = 0.0f;
    int32_t calorie_input = 0;
    memset(brand_input, '\0', brand_length + 1);
    cout << "Enter brand name of a Candty bar: ";
    cin.getline(brand_input, brand_length);
    cout << "Enter weight of the candy bar: ";
    cin >> weight_input;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> calorie_input;
    memcpy(cb.brand, brand_input, (brand_length + 1) * sizeof(char));
    cb.weight = weight_input;
    cb.calorie = calorie_input;
}
void set(CandyBar *const cb) {
    cout << "Call the set function of passing by pointer:" << endl;
    char brand_input[brand_length * 10 + 1];
    double weight_input = 0.0f;
    int32_t calorie_input = 0;
    memset(brand_input, '\0', brand_length + 1);
    cout << "Enter brand name of a Candty bar: ";
    cin.getline(brand_input, brand_length);
    cout << "Enter weight of the candy bar: ";
    cin >> weight_input;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> calorie_input;
    memcpy(cb->brand, brand_input, (brand_length + 1) * sizeof(char));
    cb->weight = weight_input;
    cb->calorie = calorie_input;
}
void show(const CandyBar &cb) {
    cout << "Call the show function of Passing by reference: " << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "calories: " << cb.calorie << endl;
}
void show(const CandyBar *cb) {
    cout << "Call the show function of Passing by pointer: " << endl;
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "calories: " << cb->calorie << endl;
}
```

### Result

#### Test Case #1:

``` log
Input: 
    AGPL 3.0
    19
    26
    MIT
    08
    17
Output:
    Enter brand name of a Candty bar: AGPL 3.0
    Enter weight of the candy bar: 19
    Enter calories (an integer value) in the candy bar: 26
    Call the show function of Passing by pointer: 
    Brand: AGPL 3.0
    Weight: 19
    calories: 26
    Call the function of passing by pointer:
    Enter brand name of a Candty bar: MIT
    Enter weight of the candy bar: 91
    Enter calories (an integer value) in the candy bar: 52
    Call the show function of Passing by reference: 
    Brand: MIT
    Weight: 8
    calories: 17
```

![picture_01](./lab08_01.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>
const int max_size = 5;
template<class T>
T max5(T *array) {
    T max_v = array[0];
    for (int32_t i = 1; i < max_size; i++) {
        if (array[i] > max_v) {
            max_v = array[i];
        }
    }
    return max_v;
}
int main() {
    int32_t int_array1[] = {159, 73, 778, 5, 75};
    double double_array1[] = {1.2, -0.23, 6.32, -11.27, 19.8};
    std::cout << "Max int : " << max5(int_array1) << std::endl;
    std::cout <<  "Max Double: " <<max5(double_array1) << std::endl;
    int32_t int_array2[] = {1, 2, 3, 4, 5};
    double double_array2[] = {1.1f, 2.0f, 3.0f, 4.0f, 5.5f};
    std::cout << "Max int: " << max5(int_array2) << std::endl;
    std::cout << "Max Double: " <<max5(double_array2) << std::endl;
    return 0;
}
```

### Result

#### Test Case #1:

``` log
Input: 
    no input.
Output:
    Max int : 778
    Max Double: 19.8
    Max int: 5
    Max Double: 5.5
```

![picture_02](./lab08_02.png)