// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1108_test.hpp"

namespace leetcode_1108 {

string leetcode_1108::defangIPaddr(const string &address) {
    const int8_t add_size{static_cast<int8_t>(address.size())};
    string will_return(add_size + 6, ' ');
    std::array<int8_t, 5> position{-1, 0, 0, 0, add_size};
    // .255.100.50.0.
    for (int8_t i{0}, cnt{1}; i < add_size; ++i) {
        if (address[i] == '.') {
            position[cnt] = i;
            cnt++;
        }
    }
    auto iter = will_return.begin();
    for (size_t i{0}; i < 3; ++i) {
        for (int8_t j = position[i] + static_cast<int8_t>(1); j < position[i + 1]; ++j) {
            (*iter) = address[j];
            ++iter;
        }
        (*iter) = '[';
        ++iter;
        (*iter) = '.';
        ++iter;
        (*iter) = ']';
        ++iter;
    }
    for (int8_t j = position[3] + static_cast<int8_t>(1); j < position[4]; ++j) {
        (*iter) = address[j];
        ++iter;
    }
    return will_return;
}
}
