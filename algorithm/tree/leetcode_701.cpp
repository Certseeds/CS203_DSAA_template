// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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