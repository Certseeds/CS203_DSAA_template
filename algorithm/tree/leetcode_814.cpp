// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_814_test.hpp"

namespace leetcode_814 {

TreeNode *pruneTree_rec(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }
    root->left = pruneTree_rec(root->left);
    root->right = pruneTree_rec(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
        return nullptr;
    }
    return root;
}

TreeNode *leetcode_814::pruneTree(TreeNode *root) {
    return pruneTree_rec(root);

}

}