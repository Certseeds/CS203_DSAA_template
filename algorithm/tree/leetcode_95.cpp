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
#include "leetcode_95_test.hpp"

namespace leetcode_95 {
vector<TreeNode *> generateTrees_rec(int32_t left, int32_t right) {
    if (left > right) {
        return vector<TreeNode *>{nullptr};
    } else if (left == right) {
        return vector<TreeNode *>{new TreeNode(left)};
    }
    vector<TreeNode *> will_return;
    for (int i = left; i <= right; i++) {
        const auto temp = generateTrees_rec(left, i - 1);
        for (auto const &j: temp) {
            const auto temp2 = generateTrees_rec(i + 1, right);
            for (auto const &k: temp2) {
                const auto will_insert = new TreeNode(i);
                will_insert->left = j;
                will_insert->right = k;
                will_return.emplace_back(will_insert);
                //will_return.emplace_back(i,j,k);
            }
        }
    }
    return will_return;
}

vector<TreeNode *> leetcode_95::generateTrees(int32_t n) {
    if (n == 0) {
        return vector<TreeNode *>{};
    }
    return generateTrees_rec(1, n);
}

}