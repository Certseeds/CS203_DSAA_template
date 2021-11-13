/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-20 19:33:40
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-20 19:35:48
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
#include <iostream>

using std::cout;
using std::endl;

void smile();

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j > i; j--) {
            smile();
        }
        cout << endl;
    }
}

void smile() {
    cout << "Smile!";
}