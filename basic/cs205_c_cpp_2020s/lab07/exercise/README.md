<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-02 20:48:14
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 21:20:45
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

# Lab07 Exercise: 2020_0402

## E1 Code & Result

### Code

``` cpp
#include <iostream>
const int row = 52;

void outputLine(const int &number, const char &ch);
void displaymenu();
int32_t Add(int32_t a, int32_t b);
int32_t Substract(int32_t a, int32_t b);
int32_t Multiply(int32_t a, int32_t b);
int32_t Divide(int32_t a, int32_t b);
int32_t Modules(int32_t a, int32_t b);
using std::cin;
using std::cout;
using std::endl;
int main() {
    int32_t(*func_array [])(int32_t a,int32_t b) = {Add,Substract,Multiply,Divide,Modules};
    char conti = 'Y';
    int32_t num1 = 0;
    int32_t num2 = 0;
    int32_t choice = 0;
    do {
        displaymenu();
        cout << "Enter your choice(1-5):";
        cin >> choice;
        if (choice <= 0 || choice >= 6) {
            cout << "Wrong choice, default use 0" << endl;
            choice = 1;
        }
        cout << "Enter your two integer numbers: ";
        cin >> num1 >> num2;
        cout << "Result:" << func_array[choice-1](num1,num2) << endl;
        cout << "Press y or Y to continue:"<<endl;
        cin >> conti;
    } while ('Y' == conti || 'y' == conti);
    return 0;
}

void outputLine(const int32_t &number, const char &ch) {
    for (int i = 0; i < number; i++) {
        cout << ch;
    }
}

void displaymenu(){
    outputLine(row, '=');
    cout << endl;
    outputLine(row / 2, ' ');
    cout << "MENU" << endl;
    outputLine(row, '=');
    cout << endl;
    cout << "   1.Add" << endl;
    cout << "   2.Subtract" << endl;
    cout << "   3.Multiply" << endl;
    cout << "   4.Divide" << endl;
    cout << "   5.Modulus" << endl;
    cout << endl;
}
int32_t Add(int32_t a, int32_t b) {
    return a + b;
}

int32_t Substract(int32_t a, int32_t b) {
    return a - b;
}


int32_t Multiply(int32_t a, int32_t b) {
    return a * b;
}

int32_t Divide(int32_t a, int32_t b) {
    return a / b;
}

int32_t Modules(int32_t a, int32_t b) {
    return a % b;
}
```

### Result

#### Test Case #1: Wrong Choice

``` log
Input:
    0
    123 456
Output:
    Wrong choice, default use 0
    Result:579
```

![picture_01](./lab07_01.png)

#### Test Case #2: Add

``` log
Input:
    1
    465 8796
Output:
    Result:9261
```

![picture_02](./lab07_02.png)

#### Test Case #3: Subtract

``` log
Input:
    2
    114 514
Output:
    Result:-400
```

![picture_03](./lab07_03.png)

#### Test Case #4: Multiply

``` log
Input:
    3
    1919 810
Output:
    Result:1554390
```

![picture_04](./lab07_04.png)

#### Test Case #5: Divide

``` log
Input:
    4
    1001 7
Output:
    Result:143
```

![picture_05](./lab07_05.png)

#### Test Case #6: Modulus

``` log
Input:
    5
    1564135 568
Output:
    Result:431
```

![picture_06](./lab07_06.png)

#### Test Case #7: Big Choice

``` log
Input:
    6
    911 027
Output:
    Wrong choice, default use 0
    Result:938
```

![picture_07](./lab07_07.png)

#### Test Case #8: continue

``` log
Input:
    0
    114 514
    y
    2
    1919 810
    y
    4
    11 51
    n
Output:
    Result:628
    Result:1109
    Result:0
```

![picture_08_1](./lab07_08_1.png)

![picture_08_2](./lab07_08_2.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void Cal_by_val(box box_in);

void Cal_by_val(box *box_in);

void Display(const box &box_in);

int main() {
    box box1 = {"ShanDong University", 11.4f, 51.4f, 19.19f, 0.0f};
    box box2 = {"JinNan College", 20.0f, 26.0f, 18.0f, 0.0f};
    std::cout << "Before setting valume by value" << std::endl;
    Display(box1);
    std::cout << "Before setting valume by address" << std::endl;
    Display(box2);
    Cal_by_val(box1);
    Cal_by_val(&box2);
    std::cout << "After setting valume by value" << std::endl;
    Display(box1);
    std::cout << "After setting valume by address" << std::endl;
    Display(box2);
    return 0;
}

void Cal_by_val(box box_in) {
    box_in.volume = box_in.height * box_in.width * box_in.length;
}

void Cal_by_val(box *box_in) {
    box_in->volume = (box_in->height) * (box_in->width) * (box_in->length);
}

void Display(const box &box_in) {
    std::cout << "Maker: " << box_in.maker << std::endl;
    std::cout << "Height: " << box_in.height << std::endl;
    std::cout << "Width: " << box_in.width << std::endl;
    std::cout << "Length: " << box_in.length << std::endl;
    std::cout << "Volume: " << box_in.volume << std::endl;
}
```

### Result

#### Test Case #1:

``` log
Input:
Output:
    Before setting valume by value
    Maker: ShanDong University
    Height: 11.4
    Width: 51.4
    Length: 19.19
    Volume: 0
    Before setting valume by address
    Maker: JinNan College
    Height: 20
    Width: 26
    Length: 18
    Volume: 0
    After setting valume by value
    Maker: ShanDong University
    Height: 11.4
    Width: 51.4
    Length: 19.19
    Volume: 0
    After setting valume by address
    Maker: JinNan College
    Height: 20
    Width: 26
    Length: 18
    Volume: 9360

```

![picture_09](./lab07_09.png)

## E3 Code & Result

### Code

``` cpp
#include <iostream>

int32_t Fill_array(double arr[], int32_t size);

void Show_array(const double *arr, int32_t size);

void Reverse_array(double *arr, int32_t size);

using std::cin;
using std::cout;
using std::endl;

int main() {
    int32_t size;
    cout << "Enter the size of the array: ";
    cin >> size;
    double *arr = new double[size];
    Fill_array(arr, size);
    Show_array(arr,size);
    Reverse_array(arr,size);
    Show_array(arr,size);
    Reverse_array(arr+1,size-2);
    Show_array(arr,size);
    delete[] arr;
    return 0;
}

int32_t Fill_array(double arr[], int32_t size) {
    for (int32_t i = 0; i < size; i++) {
        cout << "Enter value #"<< (i + 1)<<" :";
        cin >> arr[i];
        if (cin.fail()) {
            return i;
        }
    }
    return size;
}

void Show_array(const double *arr, int32_t size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout <<endl;
}

void Reverse_array(double *arr, int32_t size) {
    if (0 >= size) {
        return;
    }
    double temp = *(arr + size-1);
    *(arr + size-1) = *arr;
    *arr = temp;
    Reverse_array(arr + 1, size - 2);
}
```

### Result

#### Test Case #1: size is 1

``` log
Input:
    1
    100
Output:
    100
    100
    100
```

![picture_10](./lab07_10.png)

#### Test Case #2: size is 2

``` log
Input:
    2
    100 200
Output:
    100 200 
    200 100 
    200 100 
```

![picture_11](./lab07_11.png)

#### Test Case #3: size is 3

``` log
Input:
    3
    1234 56 789
Output:
    123 456 7931 
    7931 456 123 
    7931 456 123 
```

![picture_12](./lab07_12.png)

#### Test Case #4: size is 4

``` log
Input:
    4
    114 5145 1919 810
Output:
    114 5145 1919 810 
    810 1919 5145 114 
    810 5145 1919 114 
```

![picture_13](./lab07_13.png)

#### Test Case #5: size is 5

``` log
Input:
    5
    11 41 19 81 0
Output:
    11 41 19 19 81 
    81 19 19 41 11 
    81 41 19 19 11
```

![picture_14](./lab07_14.png)

#### Test Case #6: size is 6

``` log
Input:
    6
    43 99 71 71 37 21
Output:
    43 99 71 71 37 21 
    21 37 71 71 99 43 
    21 99 71 71 37 43 
```

![picture_15](./lab07_15.png)

#### Test Case #7: size is 7

``` log
Input:
    7
    1.5 9 7.4 6 3.0 0 7
Output:
    1.5 9 7.4 6 3 0 7 
    7 0 3 6 7.4 9 1.5 
    7 9 7.4 6 3 0 1.5 
```

![picture_16](./lab07_16.png)

#### Test Case #8: size is 8

``` log
Input:
    8
    3 7 3 5 9.2 8.5 5 9
Output:
```

![picture_17](./lab07_17.png)

#### Test Case #9: size is 16

``` log
Input:
    16
    17 65 129 513 7 255 255 255
    286 331 151 31 82 1122 408 255
Output:
    17 65 129 513 7 255 255 255 286 331 151 31 82 1122 408 255 
    255 408 1122 82 31 151 331 286 255 255 255 7 513 129 65 17 
    255 65 129 513 7 255 255 255 286 331 151 31 82 1122 408 17 
```

![picture_18](./lab07_18.png)

#### Test Case #10: input error

``` log
Input:
    8
    11 22 408 4 11 14 abc
Output:
```

![picture_19](./lab07_19.png)
