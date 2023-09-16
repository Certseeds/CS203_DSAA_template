// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1372_test.hpp"
#include <queue>

namespace leetcode_1372 {
using std::queue;

int32_t longestZigZagLeft(TreeNode *root);

int32_t longestZigZagRight(TreeNode *root);

int32_t longestZigZagLeft(TreeNode *root) {
    if (root->right == nullptr) {
        return 0;
    }
    return longestZigZagRight(root->right) + 1;
}

int32_t longestZigZagRight(TreeNode *root) {
    if (root->left == nullptr) {
        return 0;
    }
    return longestZigZagLeft(root->left) + 1;
}

int32_t leetcode_1372::longestZigZag(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int32_t maximum{longestZigZagLeft(root)}; // so we can left the other special case.
    for (queue<std::pair<TreeNode *, bool>> que{{{root, true}}}; !que.empty();) {
        const auto [head, dire] {que.front()};
        que.pop();
        if (dire) {
            const auto v = longestZigZagRight(head);
            maximum = std::max(maximum, v);
        } else {
            const auto v = longestZigZagLeft(head);
            maximum = std::max(maximum, v);
        }
        if (head->left != nullptr) {
            que.emplace(head->left, true);
        }
        if (head->right != nullptr) {
            que.emplace(head->right, false);
        }
    }
    return maximum;
}

}
