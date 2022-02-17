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
#include "leetcode_414_test.hpp"
#include <unordered_set>

namespace leetcode_414 {
using std::unordered_set;

int32_t leetcode_414::thirdMax(const vector<int32_t> &nums) {
    unordered_set<int32_t> uset;
    for (const auto i: nums) {
        uset.insert(i);
    }
    if (uset.size() < 3) {
        return *(std::max_element(uset.cbegin(), uset.cend()));
    }
    std::array<int32_t, 3> fst{std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min(),
                               std::numeric_limits<int32_t>::min()};
    for (const auto i: uset) {
        if (i > fst[2] && i != fst[1] && i != fst[0]) {
            fst[2] = i;
        }
        if (fst[2] > fst[1]) {
            std::swap(fst[1], fst[2]);
        }
        if (fst[1] > fst[0]) {
            std::swap(fst[0], fst[1]);
        }
    }
    return fst[2];
}

}