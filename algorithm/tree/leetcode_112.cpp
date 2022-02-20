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
#include "leetcode_112_test.hpp"
#include <queue>

namespace leetcode_112 {
using std::queue;

bool leetcode_112::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    for (queue<TreeNode *> now{{root}}; !now.empty();) {
        auto *head = now.front();
        now.pop();
        if (head->val == targetSum && head->left == nullptr && head->right == nullptr) {
            return true;
        }
        if (head->left != nullptr) {
            head->left->val += head->val;
            now.push(head->left);
        }
        if (head->right != nullptr) {
            head->right->val += head->val;
            now.push(head->right);
        }
    }
    return false;
}

}