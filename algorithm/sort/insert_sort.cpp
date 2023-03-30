/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:26:04
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "sort_wrapper.hpp"

using std::vector;

void insert_sort(vector<int32_t> &nums);

void sort_warpper(vector<int32_t> &nums) {
    insert_sort(nums);
}

void insert_sort(vector<int32_t> &nums) {
    int32_t will_return{0};
    const auto nums_size = static_cast<int32_t>(nums.size());
    for (int32_t i{0}; i < nums_size; ++i) {
        ++will_return;
        for (int j = i; j >= 1; --j) {
            ++will_return;
            ++will_return;
            if (nums[j - 1] > nums[j]) {
                ++will_return;
                std::swap(nums[j - 1], nums[j]);
            }
        }
        ++will_return;
    }
    ++will_return;
}
