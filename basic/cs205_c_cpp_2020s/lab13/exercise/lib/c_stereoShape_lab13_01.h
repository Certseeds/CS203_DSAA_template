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
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:28:20
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
#define CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H

inline static constexpr const double M_PI = 3.1415926535897932384;

class CStereoShape {
private:
    inline static int numberOfObject = 0;
    // or static int numberOfObject;
    // && int CStereoShape::numberOfObject = 0;
public:
    CStereoShape();

    virtual ~CStereoShape();

    virtual double GetArea();

    virtual double GetVolume();

    virtual void Show();

    static int GetNumOfObject();

};


#endif //CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
