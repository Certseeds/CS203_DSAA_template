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
#include "leetcode_700_test.hpp"

namespace leetcode_700 {

TreeNode *leetcode_700::searchBST(TreeNode *root, int32_t val) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    } else if (root->val > val) {
        return (searchBST(root->left, val));
    }
    return (searchBST(root->right, val));
}

TreeNode *leetcode_700::searchBSTiter(TreeNode *root, int32_t val) {
    TreeNode *base{root};
    while (base != nullptr) {
        if (base->val == val) {
            return base;
        } else if (base->val > val) {
            base = base->left;
        } else {
            base = base->right;
        }
    }
    return nullptr;
}
}