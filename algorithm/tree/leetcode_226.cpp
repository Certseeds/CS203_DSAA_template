// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_226_test.hpp"

namespace leetcode_226 {

TreeNode *leetcode_226::invertTree(TreeNode *const root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode *const temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}
}
