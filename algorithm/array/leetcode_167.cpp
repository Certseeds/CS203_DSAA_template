/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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
#include "leetcode_167_test.hpp"
#include <unordered_map>

namespace leetcode_167 {
using std::unordered_map;

vector<int32_t> leetcode_167::twoSum(const vector<int32_t> &numbers, int32_t target) {
    unordered_map<int32_t, int32_t> umap;
    for (size_t i{0}, nums_size{numbers.size()}; i < nums_size; i++) {
        const auto iPlus = static_cast<int32_t>(i + 1);
        if (umap.count(target - numbers[i]) != 0) {
            return {umap[target - numbers[i]], iPlus};
        } else {
            umap[numbers[i]] = iPlus;
        }
    }
    return {-1, -1};
}

vector<int32_t> leetcode_167::twoSum2(const vector<int32_t> &numbers, int32_t target) {
    int32_t begin{0};
    auto ends = static_cast<int32_t>(numbers.size() - 1);
    int32_t sum{numbers[begin] + numbers[ends]};
    while (begin < ends && sum != target) {
        if (sum > target) {
            ends--;
        } else if (sum < target) {
            begin++;
        }
        sum = numbers[begin] + numbers[ends];
    }
    return {begin + 1, ends + 1};
}
}
