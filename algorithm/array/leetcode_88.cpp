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
#include "leetcode_88_test.hpp"

namespace leetcode_88 {
void leetcode_88::merge(vector<int32_t> &nums1, int32_t m,const vector<int32_t> &nums2, int32_t n) {
    for (int32_t begin_x{m - 1}, begin_y{n - 1}, count{m + n - 1}; count >= 0; count--) {
        if (begin_x < 0) {
            // repeat with meaning
            nums1[count] = nums2[begin_y];
            begin_y--;
        } else if (begin_y < 0 || nums1[begin_x] > nums2[begin_y]) {
            nums1[count] = nums1[begin_x];
            begin_x--;
        } else {
            nums1[count] = nums2[begin_y];
            begin_y--;
        }
    }
}
}
