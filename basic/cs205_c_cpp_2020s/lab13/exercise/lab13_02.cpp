// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2023 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:34:34
 * @LastEditors  : nanoseeds
 */
#include "c_cube_lab13_02.h"
#include <iostream>

int main() {
    CStereoShape *css1 = new CCube(1, 2, 3);
    std::cout << css1->GetArea() << "\n";
    std::cout << css1->GetVolume() << "\n";
    css1->Show();
    delete css1;
    return 0;
}
