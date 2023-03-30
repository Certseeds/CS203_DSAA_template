// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_102_test.hpp"
#include <queue>

namespace leetcode_102 {
using std::queue;

vector<vector<int>> leetcode_102::levelOrder(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int32_t>> will_return{};
    for (queue<const TreeNode *> now{{root}}, next{}; !now.empty();) {
        vector<int32_t> line{};
        while (!now.empty()) {
            const auto *const head = now.front();
            now.pop();
            line.push_back(head->val);
            if (head->left != nullptr) {
                next.push(head->left);
            }
            if (head->right != nullptr) {
                next.push(head->right);
            }
        }
        will_return.push_back(line);
        std::swap(now, next);
    }
    return will_return;
}
}
