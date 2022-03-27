// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_199_test.hpp"
#include <queue>

namespace leetcode_199 {
using std::queue;

vector<int32_t> leetcode_199::rightSideView(const TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int32_t> will_return{};
    for (queue<const TreeNode *> now{{root}}, next{}; !now.empty(); std::swap(now, next)) {
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
        will_return.push_back(line.back());
    }
    return will_return;
}

}