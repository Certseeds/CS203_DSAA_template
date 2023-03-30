
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_806_test.hpp"

namespace leetcode_806 {

vector<int32_t> leetcode_806::numberOfLines(const vector<int32_t> &widths, const string &S) {
    const auto number_of_a{97};
    int line{1}, number{0};
    for (const auto ch: S) {
        if (number + widths[ch - number_of_a] <= 100) {
            number += widths[ch - number_of_a];
        } else {
            number = widths[ch - number_of_a];
            line += 1;
        }
    }
    return {line, number};
}

}
