// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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