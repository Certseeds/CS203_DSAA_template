// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2023 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-30 21:36:11
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include "lib/rectangle.h"

int main() {
    std::cout << "Rectangle 1" << std::endl;
    rectangle r1(4, 40);
    r1.display();
    std::cout << "Rectangle 2" << std::endl;
    rectangle r2(3.5, 35.9);
    r2.display();
    return 0;
}
