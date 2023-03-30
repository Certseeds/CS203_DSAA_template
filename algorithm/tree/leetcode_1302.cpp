// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1302_test.hpp"

#include <stack>

namespace leetcode_1302 {

void visit(const TreeNode *const root, vector<int32_t> &nums, int32_t depth) {
    if (root == nullptr) {
        return;
    }
    const auto length{nums.size()};
    if (length <= depth) {
        nums.push_back(0);
    }
    nums[depth] += root->val;
    visit(root->left, nums, depth + 1);
    visit(root->right, nums, depth + 1);
}

int32_t leetcode_1302::deepestLeavesSumRec(TreeNode *root) {
    vector<int32_t> nums{};
    visit(root, nums, 0);
    return nums.back();
}

int32_t leetcode_1302::deepestLeavesSumIter(TreeNode *root) {
    int32_t willReturn{0}, height{0};
    for (std::stack<std::tuple<const TreeNode *const, int32_t>> que{{std::make_tuple(root, 0)}};!que.empty();) {
        const auto [node, depth] = que.top();
        que.pop();
        if (node == nullptr) {
            continue;
        }
        if (height == depth) {
            willReturn += node->val;
        } else if (height < depth) {
            willReturn = node->val;
            height = depth;
        }
        que.push(std::make_tuple(node->left, depth + 1));
        que.push(std::make_tuple(node->right, depth + 1));
    }
    return willReturn;
}


}
