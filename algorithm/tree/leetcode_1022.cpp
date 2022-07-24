// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1022_test.hpp"
#include <stack>

namespace leetcode_1022 {
using std::stack;

int32_t leetcode_1022::sumRootToLeaf(TreeNode *root) {
    int32_t willreturn{0};
    for (stack<TreeNode *> tree{{root}}; !tree.empty();) {
        TreeNode *const begin = tree.top();
        tree.pop();
        if (begin->left == nullptr && begin->right == nullptr) {
            willreturn += begin->val;
            continue;
        }
        if (begin->left != nullptr) {
            begin->left->val += begin->val << 1;
            tree.push(begin->left);
        }
        if (begin->right != nullptr) {
            begin->right->val += begin->val << 1;
            tree.push(begin->right);
        }
    }
    return willreturn;
}

}