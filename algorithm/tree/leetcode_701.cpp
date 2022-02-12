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
#include "leetcode_701_test.hpp"

namespace leetcode_701 {

TreeNode *leetcode_701::insertIntoBST(TreeNode *root, int32_t val) {
    auto *const newnode = new TreeNode(val);
    if (root == nullptr) {
        return newnode;
    }
    for (TreeNode *base{root}; base != nullptr;) {
        if (base->val > val) {
            if (base->left == nullptr) {
                base->left = newnode;
                return root;
            }
            base = base->left;
        } else {
            if (base->right == nullptr) {
                base->right = newnode;
                return root;
            }
            base = base->right;
        }
    }
    return nullptr;
}
}