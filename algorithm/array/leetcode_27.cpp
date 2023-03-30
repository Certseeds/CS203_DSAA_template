// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_27_test.hpp"

namespace leetcode_27 {

int leetcode_27::removeElement(vector<int32_t> &vec, int32_t val) {
    vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
    return vec.size();
}

int leetcode_27::removeElement2(vector<int32_t> &vec, int32_t val) {
    const size_t vec_size{vec.size()};
    int32_t order{0};
    for (size_t begin{0}; begin < vec_size; begin++) {
        if (vec[begin] != val) {
            vec[order] = vec[begin];
            order++;
        }
    }
    vec.resize(order);
    return order;
}
}
