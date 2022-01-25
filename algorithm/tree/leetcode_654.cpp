/*
MIT License

CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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
#include "leetcode_654_test.hpp"

namespace leetcode_654 {

inline int get_max(const vector<int> &nums, size_t begin, size_t end) {
    int maxv{INT16_MIN}, posi{0};
    for (size_t i{begin}; i < end; i++) {
        if (maxv < nums[i]) {
            maxv = nums[i];
            posi = i;
        }
    }
    return posi;
}

TreeNode *rec(const vector<int> &nums, size_t begin, size_t end) {
    //cout << begin << " " << end << endl;
    if (begin == end) {
        return nullptr;
    }
    const int posi = get_max(nums, begin, end);
    auto *const willreturn = new TreeNode(nums[posi]);
    willreturn->left = rec(nums, begin, posi);
    willreturn->right = rec(nums, posi + 1, end);
    return willreturn;
}

TreeNode *leetcode_654::constructMaximumBinaryTree(const vector<int32_t> &nums) {
    return rec(nums, 0, nums.size());
}

}