/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-19 16:32:59
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-19 18:23:23
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int32_t sub_main_05_03();

int32_t while_fibonacci();

int32_t do_while_fibonacci();

int32_t for_fibonacci();

static constexpr const char *const input_str = "Enter a positive number: ";
static constexpr const char *const output_str = "Fibonacci Series: ";
static constexpr const char *const illegal_str = "Please input positive";
#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_

int main() {
    // Path is
    // 相对路径: /cmake-build-debug/lab05/test
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