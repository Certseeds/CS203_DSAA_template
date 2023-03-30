// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_113_test.hpp"
#include <queue>

namespace leetcode_113 {
using std::queue;


vector<vector<int>> leetcode_113::pathSum(TreeNode *root, int target) {
    vector<vector<int32_t>> sums;
    if (root == nullptr) {
        return sums;
    }
    for (queue<std::pair<TreeNode *, const vector<int32_t>>> now{{{root, {root->val}}}}; !now.empty();) {
        const auto[head, vec] = now.front();
        now.pop();
        if (head->val == target && head->left == nullptr && head->right == nullptr) {
            sums.push_back(vec);
            continue;
        }
        if (head->left != nullptr) {
            vector<int32_t> path{vec};
            path.push_back(head->left->val);
            head->left->val += head->val;
            now.emplace(head->left, path);
        }
        if (head->right != nullptr) {
            vector<int32_t> path{vec};
            path.push_back(head->right->val);
            head->right->val += head->val;
            now.emplace(head->right, path);
        }
    }
    return sums;
}


}
