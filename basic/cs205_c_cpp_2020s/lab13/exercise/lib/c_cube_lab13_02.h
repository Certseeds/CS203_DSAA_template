/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:57:28
 */
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
#ifndef CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
#define CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H

#include "c_stereoShape_lab13_01.h"

class CCube : public CStereoShape {
private:
    double length{0.0f};
    double width{0.0f};
    double height{0.0f};
public:
    CCube() = default;

    CCube(double len, double wid, double heig);

    // 拷贝构造函数 Copy Constructor
    CCube(const CCube &CC);

    double GetArea() override;

    double GetVolume() override;

    void Show() override;
};


#endif //CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
