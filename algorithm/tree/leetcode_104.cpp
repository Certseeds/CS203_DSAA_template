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
#include "leetcode_104_test.hpp"

namespace leetcode_104 {

int32_t leetcode_104::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    root->val = 1;
    int32_t will_return{1};
    stack<TreeNode *> tree{{root}};
    while (!tree.empty()) {
        const TreeNode *begin = tree.top();
        tree.pop();
        if (begin->left == nullptr && begin->right == nullptr) {
            will_return = std::max(will_return, begin->val);
            continue;
        }
        if (begin->left != nullptr) {
            begin->left->val = begin->val + 1;
            tree.push(begin->left);
        }
        if (begin->right != nullptr) {
            begin->right->val = begin->val + 1;
            tree.push(begin->right);
        }
    }
    return will_return;
}
}