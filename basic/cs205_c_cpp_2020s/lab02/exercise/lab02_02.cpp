/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:33
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-28 16:19:14
 */
/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

static constexpr const int32_t hours_number = 24;
static constexpr const int32_t minute_number = 60;
static constexpr const int32_t second_number = 60;
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
    int64_t seconds = 0;
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
    int64_t days = seconds / (hours_number * minute_number * second_number);
    seconds = seconds % (hours_number * minute_number * second_number);
    int64_t hours = seconds / (minute_number * second_number);
    seconds %= (minute_number * second_number);
    int64_t minutes = seconds / second_number;
    seconds %= second_number;
    cout << " " << "seconds = " << days << " days, " << hours;
    cout << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    return 0;
}