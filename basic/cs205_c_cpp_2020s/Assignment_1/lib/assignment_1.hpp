/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-05 21:56:08
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:04:31
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
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int sub_main();

int get_city_itude(vector<double> &dous, vector<string> &strs, const string &num, int order);

bool judge_legal(const string &s);

bool judge_legal2(const string &s);

string delete_space(string str);

int give_two_double(const string &s, vector<double> &num, int order);

bool check_double(const string &s);

double count_distance(vector<double> &dous);

static constexpr const int32_t max_length = 1024;
static constexpr const int32_t radius_earth = 6371;
static constexpr const double PI = 3.1415926535;
