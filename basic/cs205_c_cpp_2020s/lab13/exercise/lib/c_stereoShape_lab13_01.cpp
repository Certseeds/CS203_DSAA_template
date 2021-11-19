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
