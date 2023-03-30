// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_13_test.hpp"
#include <array>
#include <cstring>

namespace leetcode_13 {
using std::array;

int32_t leetcode_13::romanToInt(const string &s) {
    constexpr const static array<array<const char *const, 9>, 3> vas{
            {{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
             {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
             {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}}
    };
    int32_t will_return{0};
    size_t begin{0};
    int32_t added{1000};
    while (s[begin] == 'M') {
        will_return += added;
        begin++;
    }
    for (const auto &i: vas) {
        added /= 10;
        for (auto j{i.crbegin()}; j != i.crend(); j++) {
            const auto jsize{strlen(*j)};
            if (!s.compare(begin, jsize, *j, 0, jsize)) {
                will_return += std::distance(j, i.crend() - 1 + 1) * added;
                begin += jsize;
                break;
            }
        }
    }
    return will_return;
}
}
