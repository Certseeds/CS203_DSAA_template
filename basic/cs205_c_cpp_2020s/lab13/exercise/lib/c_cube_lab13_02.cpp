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
 * @Date: 2020-05-17 10:48:32
 * @LastEditors  : nanoseeds
 */
#include "c_cube_lab13_02.h"
#include <iostream>


CCube::CCube(double len, double wid, double heig) {
    this->length = len;
    this->width = wid;
    this->height = heig;
}

CCube::CCube(const CCube &CC) {
    this->length = CC.length;
    this->width = CC.width;
    this->height = CC.height;
}

double CCube::GetArea() {
    return this->length * this->width * this->height;
}

double CCube::GetVolume() {
    return 2 * this->length * this->width \
 + 2 * this->width * this->height \
 + 2 * this->length * this->height;
}

void CCube::Show() {
    std::cout << "length is " << this->length << "\n";
    std::cout << "width is " << this->width << "\n";
    std::cout << "height is " << this->height << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
