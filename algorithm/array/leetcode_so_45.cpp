/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_so_45_test.hpp"

namespace leetcode_so_45 {

string leetcode_so_45::minNumber(const vector<int32_t> &numsImmutable) {
    auto nums{numsImmutable};
    const auto comp = [](auto nums1, auto nums2) {
        const auto tovec = [](auto nums_fst, auto nums_snd) {
            vector<uint8_t> vec{};
            if (nums_fst == 0) { vec.push_back(0); }
            for (; nums_fst != 0; nums_fst /= 10) { vec.push_back(nums_fst % 10); }
            if (nums_snd == 0) { vec.push_back(0); }
            for (; nums_snd != 0; nums_snd /= 10) { vec.push_back(nums_snd % 10); }
            return vector<uint8_t>{vec.crbegin(), vec.crend()};
            // TODO,此处可优化
        };
        const vector<uint8_t> fst = tovec(nums1, nums2), snd = tovec(nums2, nums1);
        const auto length = fst.size();
        for (size_t i{0}; i < length; ++i) {
            if (fst[i] > snd[i]) {
                return true;
            } else if (fst[i] < snd[i]) {
                return false;
            }
        }
        return false;
    };
    std::sort(nums.begin(), nums.end(), comp);
    string will_return{};
    for (const auto num: nums) {
        will_return += std::to_string(num);
    }
    return will_return;
}
}
