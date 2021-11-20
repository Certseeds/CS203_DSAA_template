<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-28 22:16:11
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:41:17
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 18.04),C++17, Cmake 3.16.6.

# Lab15 Exercise: 2020_0528

## E Code & Result

### Code

``` cpp
#include <array>
#include <cmath>
#include <stdexcept>
#include <iostream>
double_t calculateAverage(int32_t a, int32_t b, int32_t c, int32_t d);
struct OutOfRangeException : public std::exception {
    char will_return[100] = "\n";
    explicit OutOfRangeException(int32_t loca, int32_t val) {
        sprintf(will_return, "The parameter%d is %d which out of range(0-100)", loca, val);
    }
    [[nodiscard]] const char *what() const noexcept override {
        return will_return;
    }
};
int main() {
    std::cout << "Please enter marks for 4 courses:";
    std::array<int32_t, 4> arr = {0, 0, 0, 0};
    for (auto &item : arr) {
        std::cin >> item;
    }
    double_t temp = -1.0f;
    try {
        temp = calculateAverage(arr[0], arr[1], arr[2], arr[3]);
    } catch (OutOfRangeException &oore) {
        std::cerr << "\033[31m" << oore.what() << std::endl;
    }
    if (temp >= 0) {
        std::cout << "The avarage of the four courses is " << temp;
    }
    return (0);
}
double_t calculateAverage(int32_t a, int32_t b, int32_t c, int32_t d) {
    std::array<int32_t, 4> arr = {a, b, c, d};
    double_t result = 0.0f;
    for (uint32_t i = 0; i < arr.size(); ++i) {
        if (arr.at(i) > 100 || arr.at(i) < 0) {
            throw OutOfRangeException(i, arr.at(i));
        }
        result += arr.at(i);
    }
    return result / arr.size();
}
```

### Result

#### Test Case #1

``` log
Input:
    60 80 90 100
Output:
    The avarage of the four courses is 82.5
```

![picture_01](./lab15_01.png)

#### Test Case #2

``` log
Input:
    90 -80 70 80
Output:
    The parameter1 is -80 which out of range(0-100)
```

![picture_02](./lab15_02.png)

#### Test Case #3

``` log
Input:
    80 90 110 80
Output:
    The parameter1 is 110 which out of range(0-100)
```

![picture_03](./lab15_03.png)