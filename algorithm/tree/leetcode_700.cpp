// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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