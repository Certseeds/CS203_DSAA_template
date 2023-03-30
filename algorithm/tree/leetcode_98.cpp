// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_98_test.hpp"

namespace leetcode_98 {

bool smaller(TreeNode *root, int32_t value);

bool bigger(TreeNode *root, int32_t value);

bool leetcode_98::isValidBST(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    return smaller(root->left, root->val) && bigger(root->right, root->val);
}

bool smaller(TreeNode *root, int32_t value) {
    if (root == nullptr) {
        return true;
    }
    return root->val < value &&
           smaller(root->right, value) && smaller(root->left, root->val) &&
           bigger(root->right, root->val);
}

bool bigger(TreeNode *root, int32_t value) {
    if (root == nullptr) {
        return true;
    }
    return root->val > value &&
           smaller(root->left, root->val) &&
           bigger(root->left, value) && bigger(root->right, root->val);
}

}
