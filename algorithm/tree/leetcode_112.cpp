// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_112_test.hpp"
#include <queue>

namespace leetcode_112 {
using std::queue;

bool leetcode_112::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    for (queue<TreeNode *> now{{root}}; !now.empty();) {
        auto *head = now.front();
        now.pop();
        if (head->val == targetSum && head->left == nullptr && head->right == nullptr) {
            return true;
        }
        if (head->left != nullptr) {
            head->left->val += head->val;
            now.push(head->left);
        }
        if (head->right != nullptr) {
            head->right->val += head->val;
            now.push(head->right);
        }
    }
    return false;
}

}
