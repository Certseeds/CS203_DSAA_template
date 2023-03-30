// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_26_test.hpp"

namespace leetcode_26 {
int32_t leetcode_26::removeDuplicates(vector<int32_t> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int32_t last{nums.front() - 1}, count{0};
    for (auto &num: nums) {
        if (num != last) {
            last = num;
            nums[count] = num;
            count++;
        }
    }
    nums.resize(count);
    return count;
}
}
