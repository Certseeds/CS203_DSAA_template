// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_230_test.hpp"
#include <stack>

namespace leetcode_230 {
using std::stack;

int32_t leetcode_230::kthSmallest(TreeNode *root, int32_t k) {
    if (root == nullptr) {
        return -1;
    }
    for (stack<TreeNode *> sta; root != nullptr || !sta.empty(); root = root->right) {
        for (; root != nullptr; root = root->left) {
            sta.push(root);
        }
        root = sta.top();
        sta.pop();
        --k;
        if (k == 0) {
            break;
        }
    }
    return root->val;
}
}
