// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_922_test.hpp"

namespace leetcode_922 {


vector <int32_t> leetcode_922::sortArrayByParityII(const vector <int32_t> &nums) {
    vector <int32_t> will_return{nums};
    const auto nums_size{will_return.size()};
    size_t sing{0};
    int64_t doub{static_cast<int64_t>(nums_size) - 1};
    for (; sing < nums_size && will_return[sing] % 2 == 0; sing += 2) {}
    for (; doub > 0 && will_return[doub] % 2 == 1; doub -= 2) {}
    while (sing < nums_size && doub > 0) {
        std::swap(will_return[sing], will_return[doub]);
        for (; sing < nums_size && will_return[sing] % 2 == 0; sing += 2) {}
        for (; doub > 0 && will_return[doub] % 2 == 1; doub -= 2) {}
    }
    return will_return;
}
}
