// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_101_test.hpp"

namespace leetcode_101 {
bool isSym(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    } else if ((left == nullptr) != (right == nullptr)) {
        return false;
    }
    return left->val == right->val && isSym(left->left, right->right) && isSym(left->right, right->left);
}

bool leetcode_101::isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    return isSym(root->left, root->right);
}


}
