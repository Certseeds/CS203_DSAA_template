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
 * @Date: 2020-05-17 11:08:55
 * @LastEditors  : nanoseeds
 */
#include "c_sphere_lab13_03.h"
#include <cmath>
#include <iostream>

CSphere::CSphere(double rad) {
    this->radius = rad;
}

CSphere::CSphere(const CSphere &CC) {
    this->radius = CC.radius;
}

double CSphere::GetArea() {
    return 4.0f * M_PI * pow(this->radius, 2);
}

double CSphere::GetVolume() {
    return 4.0f / 3.0f * M_PI * pow(this->radius, 3);
}

void CSphere::Show() {
    std::cout << "radius is " << this->radius << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
