// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_104_test.hpp"

namespace leetcode_104 {

int32_t leetcode_104::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    root->val = 1;
    int32_t will_return{1};
    stack<TreeNode *> tree{{root}};
    while (!tree.empty()) {
        const TreeNode *begin = tree.top();
        tree.pop();
        if (begin->left == nullptr && begin->right == nullptr) {
            will_return = std::max(will_return, begin->val);
            continue;
        }
        if (begin->left != nullptr) {
            begin->left->val = begin->val + 1;
            tree.push(begin->left);
        }
        if (begin->right != nullptr) {
            begin->right->val = begin->val + 1;
            tree.push(begin->right);
        }
    }
    return will_return;
}
}
