/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 13:33:24
 */
/* CS205_C_CPP
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
 * @Date: 2020-03-26 23:05:19
 * @LastEditors  : nanoseeds
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    double quiz = 0;
    double mid_term = 0;
    double scores = 0;
    double average = 0;
    cout << "Input scores between 0 to 100" << endl;
    cout << "Input quiz Score : ";
    cin >> quiz;
    while ((getchar()) != '\n');
    cout << "Input mid_term Score : ";
    cin >> mid_term;
    while ((getchar()) != '\n');
    cout << "Input final term Score : ";
    cin >> scores;
    while ((getchar()) != '\n');
    average = (quiz + mid_term + scores) / 3;
    char grade = '\0';
    if (average >= 90) {
        grade = 'A';
    } else if (average >= 70) {
        grade = 'B';
    } else if (average >= 50) {
        grade = 'C';
    } else {
        grade = 'F';
    }
    cout << "Average is : " << average << endl;
    cout << "Grade is : " << grade << endl;
    return 0;
}