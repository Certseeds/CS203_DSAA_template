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
#include "leetcode_so_26_test.hpp"

namespace leetcode_so_26 {
bool in(TreeNode *A, TreeNode *B) {
    if (B == nullptr) {
        return true;
    } else if (A == nullptr) {
        return false;
    }
    return A->val == B->val && in(A->left, B->left) && in(A->right, B->right);
}

bool leetcode_so_26::isSubStructure(TREE_NODE::TreeNode<int32_t> *A, TREE_NODE::TreeNode<int32_t> *B) {
    if (B == nullptr || A == nullptr) {
        return false;
    }
    return in(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

}