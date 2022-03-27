// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
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