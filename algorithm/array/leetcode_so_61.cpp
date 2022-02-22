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
#include "leetcode_so_61_test.hpp"
#include <array>

namespace leetcode_so_61 {
using std::array;

bool leetcode_so_61::isStraight(const vector<int32_t> &nums) {
    if (nums.size() != 5) {
        return false;
    }
    std::array<uint8_t, 14> umap{0};// 0 to 13
    int32_t maxV{-1}, minV{114514}, zeros{0};
    for (const auto num: nums) {
        if (num == 0) {
            ++zeros;
        } else {
            if (umap[num] == 0) {
                umap[num] = 1;
            } else {
                return false;
            }
            maxV = std::max(maxV, num);
            minV = std::min(minV, num);
        }
    }
    const auto maxDiff{maxV - minV};
    if (maxDiff > 4 || maxDiff + zeros < 4) {
        return false;
    }
    return true;
}

}
