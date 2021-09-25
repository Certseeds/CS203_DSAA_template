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
#include "leetcode_15_test.hpp"

namespace leetcode_15 {

vector<vector<int32_t>> leetcode_15::threeSum(vector<int32_t> &nums) {
    vector<vector<int32_t>> will_return{};
    if (nums.size() < 3) {
        return will_return;
    }
    int32_t zero_nums{0};
    unordered_map<int32_t, int32_t> umap;
    for (const auto &i: nums) {
        umap[i] += (umap[i] <= 1);
        zero_nums += (i == 0);
    }
    size_t count{0};
    for (const auto &key  :umap) {
        nums[count] = key.first;
        count++;
    }
    nums.resize(count);
    std::sort(std::begin(nums), std::end(nums), std::less<>());
    if (nums[0] > 0 || nums[count - 1] < 0) {
        return will_return;
    }
    size_t first_bigger_than_zero{0};
    for (size_t i = 0; i < count; i++) {
        if (nums[i] > 0) {
            first_bigger_than_zero = i;
            break;
        }
    }
    for (size_t begin_t{0}; begin_t < first_bigger_than_zero; begin_t++) {
        for (size_t end_t{count - 1}; end_t >= first_bigger_than_zero; end_t--) {
            auto sum2 = nums[begin_t] + nums[end_t];
            auto iter = umap.find(-sum2);
            if ((iter != std::end(umap)) && ((-sum2 > nums[begin_t] && -sum2 < nums[end_t])
                                             || (-sum2 == nums[begin_t] && iter->second == 2)
                                             || (-sum2 == nums[end_t] && iter->second == 2)
            )) {
                will_return.emplace_back(std::initializer_list<int32_t>{nums[begin_t], -sum2, nums[end_t]});
            }
        }
    }
    if (zero_nums >= 3) {
        will_return.push_back(vector<int32_t>{0, 0, 0});
    }
    return will_return;
}
}