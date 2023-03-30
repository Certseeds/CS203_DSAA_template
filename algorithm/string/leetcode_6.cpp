// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_6_test.hpp"

namespace leetcode_6 {
string leetcode_6::convert(const string &s, int numRows) {
    const auto s_size{s.size()}, numRows_size{static_cast<size_t>(numRows)};
    if (s_size <= numRows_size || numRows_size == 1) {
        return s;
    }
    vector<uint8_t> vec(s_size);
    const size_t batch{numRows_size * 2 - 2},
            block_number{s_size / batch},
            batch_size{batch * block_number},
            left_num{s_size - batch_size};
    size_t count{0uLL};
    for (size_t i{0}; i < s_size; i += batch, count++) {
        vec[count] = s[i];
    }
    for (size_t i{1}; i < numRows_size - 1; i++) {
        for (size_t j{0}; j < batch_size; j += batch, count += 2) {
            vec[count] = s[j + i];
            vec[count + 1] = s[j + batch - i];
        }
        if (left_num > i) {
            vec[count] = s[batch_size + i];
            count++;
            if (left_num > batch - i) {
                vec[count] = s[batch_size + batch - i];
                count++;
            }
        }
    }
    for (size_t i{0}; i < batch_size; i += batch, count++) {
        vec[count] = s[i + (numRows_size - 1)];
    }
    if (left_num >= numRows_size) {
        vec[count] = s[batch_size + numRows_size - 1];
    }
    return {vec.cbegin(), vec.cend()};
}

}
