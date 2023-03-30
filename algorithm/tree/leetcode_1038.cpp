// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1038_test.hpp"

namespace leetcode_1038 {

int32_t rec(TreeNode *const root, int32_t sum) { // 最小和数大概是反过来?
    if (root == nullptr) {
        return sum;
    }
    const auto rightMax{rec(root->right, sum)};
    root->val += rightMax;
    const auto leftMax{rec(root->left, root->val)};
    return leftMax;
}

TreeNode *leetcode_1038::bstToGst(TreeNode *root) {
    rec(root, 0);
    return root;
}

}
