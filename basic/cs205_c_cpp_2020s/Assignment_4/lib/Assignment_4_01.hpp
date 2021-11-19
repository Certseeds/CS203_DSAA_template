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
 * @Date: 2020-04-19 21:00:12
 * @LastEditors  : nanoseeds
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
//  [2000,2020]
static constexpr const std::pair<int32_t, int32_t> range(2000, 2020);
// lab number
static constexpr const int32_t lab_number = 14;
extern unordered_map<int32_t, vector<int32_t>> umap;

int32_t question1();