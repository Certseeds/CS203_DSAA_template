// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_653_test.hpp"

namespace leetcode_653 {
TreeNode *leetcode_653::lowestCommonAncestor(TreeNode *root, const TreeNode *const p, const TreeNode *const q) {
    if (root->val > std::max(p->val, q->val)) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < std::min(p->val, q->val)) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

}