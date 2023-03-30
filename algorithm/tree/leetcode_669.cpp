// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_669_test.hpp"

namespace leetcode_669 {

TreeNode *leetcode_669::trimBST(TreeNode *root, int L, int R) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val < L) {
        root->left = nullptr;
        return trimBST(root->right, L, R);
    } else if (root->val > R) {
        root->right = nullptr;
        return trimBST(root->left, L, R);
    }
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}

}
