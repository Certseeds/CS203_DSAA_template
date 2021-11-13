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
/**
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-28 20:49:11
 * @LastEditors  : nanoseeds
 */
#include <array>
#include <cmath>
#include <stdexcept>
#include <iostream>

double_t calculateAverage(int32_t a, int32_t b, int32_t c, int32_t d);

struct OutOfRangeException : public std::exception {
    char will_return[100] = "\0";

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
    for (auto &item: arr) {
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