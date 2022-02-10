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
#include "leetcode_350_test.hpp"
#include <unordered_map>

namespace leetcode_350 {
using std::unordered_map;

vector<int32_t> leetcode_350::intersect(const vector<int32_t> &nums1, const vector<int32_t> &nums2) {
    const auto *nums1Ref = &nums1;
    const auto *nums2Ref = &nums2;
    const auto nums1_size{nums1.size()}, nums2_size{nums2.size()};
    if (nums1_size >= nums2_size) {
        std::swap(nums1Ref, nums2Ref);
    }
    // nums1.size() < nums2.size()
    unordered_map<int32_t, int32_t> umap1;
    for (const auto i: *nums1Ref) {
        umap1[i]++;
    }
    vector<int32_t> will_return;
    will_return.reserve(nums2_size);
    for (const auto i: *nums2Ref) {
        if (umap1[i] > 0) {
            umap1[i]--;
            will_return.push_back(i);
        }
    }
    return will_return;
}
}
