/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-19 16:32:26
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-19 18:23:14
 */
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