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
 * @Date: 2020-05-17 11:31:19
 * @LastEditors  : nanoseeds
 */
#include "c_cube_lab13_02.h"
#include "c_sphere_lab13_03.h"
#include <iostream>

int main() {
    CCube a_cube{4.0f, 5.0f, 6.0f};
    CSphere c_sphere{7.9f};
    CStereoShape *p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    std::cout << CStereoShape::GetNumOfObject();
    return 0;
}