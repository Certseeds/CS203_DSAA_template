// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:34:34
 * @LastEditors  : nanoseeds
 */
#include "c_stereoShape_lab13_01.h"
#include <iostream>

int main() {
    CStereoShape css1{};
    std::cout << css1.GetArea() << "\n";
    std::cout << css1.GetVolume() << "\n";
    css1.Show();
    CStereoShape::GetNumOfObject();
    return 0;
}