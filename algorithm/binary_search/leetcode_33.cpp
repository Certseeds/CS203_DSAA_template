/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
#include "leetcode_33_test.hpp"

namespace leetcode_33 {

int32_t leetcode_33::search(const vector<int32_t> &nums, int32_t target) {
    const auto nums_size{static_cast<int32_t>(nums.size())};
    if (nums.empty()) {
        return -1;
    } else if (nums_size == 1) {
        return (nums[0] == target) ? 0 : -1;
    }
    int32_t minv{nums.back()}, first{0}, maxv{1};
    while (maxv * 2 < nums_size) {
        maxv *= 2;
    }
    while (maxv != 0) {
        //cout << first <<" " << maxv << lastl;
        if (first + maxv < nums_size && nums[first + maxv] > minv) {
            first += maxv;
        }
        maxv /= 2;
    }
    const auto &binary_search_find_first_equal = [target, &nums](auto begin, auto end) {
        int32_t middle{0};
        while (begin < static_cast<int32_t>(end)) {
            middle = (end - begin) / 2 + begin;
            if (target == nums[middle]) {
                return middle;
            } else if (target > nums[middle]) {
                begin = middle + 1;
            } else {
                end = middle;
            }
        }
        return -1;
    };
    if (const int x1{binary_search_find_first_equal(0, first + 1)};x1 != -1) {
        return x1;
    }
    return binary_search_find_first_equal(first + 1, nums.size());
}

}