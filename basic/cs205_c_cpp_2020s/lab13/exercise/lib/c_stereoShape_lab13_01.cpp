// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:28:20
 * @LastEditors  : nanoseeds
 */
#include "c_stereoShape_lab13_01.h"
#include <iostream>


CStereoShape::CStereoShape() {
    numberOfObject++;
}

double CStereoShape::GetArea() {
    std::cout << "CStereoShape::GetArea()" << std::endl;
    return 0.0;
}

double CStereoShape::GetVolume() {
    std::cout << "CStereoShape::GetVolume()" << std::endl;
    return 0.0;
}

void CStereoShape::Show() {
    std::cout << "CStereoShape::Show()" << std::endl;
}

int CStereoShape::GetNumOfObject() {
    return CStereoShape::numberOfObject;
}

CStereoShape::~CStereoShape() {
    numberOfObject--;
}
