// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_338_test.hpp"

namespace leetcode_338 {

vector<int32_t> leetcode_338::countBits(int32_t num) {
    if (num == 0) {
        return {0};
    }
    vector<int32_t> will_return(num + 1, 0);
    will_return[0] = 0;
    will_return[1] = 1;
    for (int32_t i{2}; i < num + 1; ++i) {
        will_return[i] = will_return[i / 2] + i % 2;
    }
    return will_return;
}

}
