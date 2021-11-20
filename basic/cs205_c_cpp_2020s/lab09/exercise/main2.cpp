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

 * @Author: nanoseeds
 * @Date: 2020-04-18 10:27:24
 * @LastEditors  : nanoseeds
 */
#include "CandyBar.h"
#include <iostream>
#include <string>

int main() {
    CandyBar *cb = new CandyBar[5];
    uint32_t number;
    std::cout << "Please enter the number of candybar:" << std::endl;
    std::cin >> number;
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        if (0 != setCandyBar(cb[i])) {
            delete[] cb;
            return 0;
        }
    }
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        showCandyBar(cb[i]);
    }
    delete[] cb;
    return 0;
}
