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
#include "leetcode_1_test.hpp"
#include <unordered_map>

namespace leetcode_1 {
using std::unordered_map;

vector<int32_t> leetcode_1::twoSum(const vector<int32_t> &nums, int32_t target) {
    const auto nums_size{nums.size()};
    unordered_map<int32_t, int32_t> umaps;
    for (size_t i{0}; i < nums_size; i++) {
        if (umaps.find(target - nums[i]) != std::end(umaps)) {
            return {static_cast<int32_t>(i), umaps[target - nums[i]] - 1};
        }
        umaps[nums[i]] = static_cast<int32_t>(i) + 1;
    }
    return {};
}
/*
if the number is not so big, it's better to use brute force,
if number > 50,choose hashmap.
 */
}