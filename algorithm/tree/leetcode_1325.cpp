// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1325_test.hpp"

namespace leetcode_1325 {

TreeNode *leetcode_1325::removeLeafNodesRec(TreeNode *root, int target) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode *const left = removeLeafNodesRec(root->left, target);
    TreeNode *const right = removeLeafNodesRec(root->right, target);
    if (left == nullptr && right == nullptr) {
        if (root->val == target) {
            return nullptr;
        }
    }
    root->left = left;
    root->right = right;
    return root;
}

}