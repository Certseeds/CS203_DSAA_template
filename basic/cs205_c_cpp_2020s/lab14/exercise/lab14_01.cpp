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
 * @Date: 2020-05-23 11:01:42
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <string>

using namespace std;

//Make a template out of the prototype
template<typename T>
T Max(T one, T two);

int main() {
    int i_one = 3, i_two = 5;
    cout << "The max of " << i_one << " and " << i_two << " is "
         << Max<int>(i_one, i_two) << endl;
//Test your template on float and string types
    double double_one = 5.6f, double_two = 7.3f;
    cout << "The max of " << double_one << " and " << double_two << " is "
         << Max<double>(double_one, double_two) << endl;
    string str_one = "donkey", str_two = "apple";
    cout << "The max of " << str_one << " and " << str_two << " is "
         << Max<string>(str_one, str_two) << endl;
    return 0;
}

template<typename T>
T Max(T one, T two) {
    T biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}