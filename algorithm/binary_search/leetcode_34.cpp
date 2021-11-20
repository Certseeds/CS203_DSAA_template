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
#include "leetcode_34_test.hpp"

namespace leetcode_34 {
using binary_search::binary_search_pos;

vector<int32_t> leetcode_34::searchRange(const vector<int32_t> &nums, int32_t target) {
    if (nums.empty()) {
        return vector<int32_t>{-1, -1};
    }
    if (binary_search_pos(nums, target, 0, static_cast<int32_t>(nums.size())) == -1) {
        return vector<int32_t>{-1, -1};
    }
    const auto minv{static_cast<int32_t>(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin())},
            maxv{static_cast<int32_t>(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin())};
    return vector<int32_t>{minv, maxv - 1};
}

}