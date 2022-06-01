// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_938_test.hpp"

namespace leetcode_938 {

int32_t leetcode_938::rangeSumBST(TreeNode *root, int32_t low, int32_t high) {
    if (root == nullptr)
        return 0;
    int32_t willreturn{0};
    willreturn += ((root->val >= low) && (root->val <= high)) ? root->val : 0;
    if (root->val >= high) {
        willreturn += rangeSumBST(root->left, low, high);
    } else if (root->val > low && root->val < high) {
        willreturn += rangeSumBST(root->left, low, high);
        willreturn += rangeSumBST(root->right, low, high);
    } else {
        willreturn += rangeSumBST(root->right, low, high);
    }
    return willreturn;
}

}