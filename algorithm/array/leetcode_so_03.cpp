// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_so_03_test.hpp"
#include <unordered_map>

namespace leetcode_so_03 {
using std::unordered_map;

int32_t leetcode_so_03::findRepeatNumber(const vector<int32_t> &nums_) {
    vector<int32_t> nums{nums_};
    std::sort(nums.begin(), nums.end());
    for (size_t i{0}, size{nums.size()}; i + 1 < size; ++i) {
        if (nums[i] == nums[i + 1]) {
            return nums[i];
        }
    }
    return 0;
}

int32_t leetcode_so_03::findRepeatNumber2(const vector<int32_t> &nums) {
    unordered_map<int32_t, size_t> umap;
    for (size_t i{0}, size{nums.size()}; i < size; ++i) {
        ++umap[nums[i]];
        if (umap[nums[i]] == 2) {
            return nums[i];
        }
    }
    return -1;
}

int32_t leetcode_so_03::findRepeatNumber3(const vector<int32_t> &nums_) {
    vector<int32_t> nums{nums_};
    for (size_t i{0}, size{nums.size()}; i < size; ++i) {
        const auto num = [](const auto i) {
            return i >= 0 ? i : -i - 1;
        }(nums[i]);
        if (nums[num] < 0) {
            return num;
        }
        nums[num] = -nums[num] - 1;
    }
    return -1;
}

}
