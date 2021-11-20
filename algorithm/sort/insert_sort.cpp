/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:26:04
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
    for (int32_t i{0}; i < nums_size; i++) {
        will_return++;
        for (int j = i; j >= 1; j--) {
            will_return++;
            will_return++;
            if (nums[j - 1] > nums[j]) {
                will_return++;
                std::swap(nums[j - 1], nums[j]);
            }
        }
        will_return++;
    }
    will_return++;
}