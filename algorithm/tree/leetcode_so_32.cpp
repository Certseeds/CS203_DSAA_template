// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_so_32_test.hpp"
#include "traverse.cpp"
#include <queue>

namespace leetcode_so_32 {
using std::queue;
using namespace Tree_Traverse;

vector<int32_t> leetcode_so_32::levelOrderFst(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int32_t> will_return{};
    const auto func = [&will_return](const auto node) {
        will_return.push_back(node->val);
    };
    iter::level(root, func);
    return will_return;
}

vector<vector<int32_t>> leetcode_so_32::levelOrderTrd(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int32_t>> will_return{};
    bool shift{true};
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
        if (shift) {
            will_return.emplace_back(line.begin(), line.end());
        } else {
            will_return.emplace_back(line.rbegin(), line.rend());
        }
        shift = !shift;
        std::swap(now, next);
    }
    return will_return;
}

}