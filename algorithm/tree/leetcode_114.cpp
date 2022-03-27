// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_114_test.hpp"
#include <stack>

namespace leetcode_114 {
using std::stack;

void leetcode_114::flatten(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    TreeNode base{-1};
    TreeNode *last = &base;
    for (stack<TreeNode *> sta{{root}}; !sta.empty();) {
        TreeNode *const head = sta.top();
        sta.pop();
        if (head->right != nullptr) {
            sta.push(head->right);
        }
        if (head->left != nullptr) {
            sta.push(head->left);
        }
        last->right = head;
        last->left = nullptr;
        last = head;
    }
}

}