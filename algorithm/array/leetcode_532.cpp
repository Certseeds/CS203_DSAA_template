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
#include "leetcode_532_test.hpp"

namespace leetcode_532 {

int32_t leetcode_532::findPairs(const vector<int32_t> &nums, int32_t k) {
    if (k < 0) {
        return 0;
    }
    unordered_map<int32_t, int32_t> umap;
    int count = 0;
    for (const auto num: nums) {
        umap[num]++;
    }
    if (k == 0) {
        return std::accumulate(umap.cbegin(), umap.cend(), 0,
                               [](const auto base, const auto value) { return base + (value.second > 1); });
    }
    for (auto i: umap) {
        count += (umap.count(i.first + k) > 0);
    }
    return count;
}

}
