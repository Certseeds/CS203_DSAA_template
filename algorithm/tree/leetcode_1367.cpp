// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1367_test.hpp"
#include <queue>

namespace leetcode_1367 {
using std::queue;

bool isSubPathRec(ListNode *head, TreeNode *root) {
    if (head == nullptr) {
        return true;
    }
    if (root == nullptr) {
        return false;
    }
    if (head->val != root->val) {
        return false;
    }
    const auto left = isSubPathRec(head->next, root->left);
    const auto right = isSubPathRec(head->next, root->right);
    return left || right;
}

bool leetcode_1367::isSubPath(ListNode *head, TreeNode *root) {
    if (head == nullptr) {
        return true;
    } else if (root == nullptr) {
        return false;
    }
    for (queue<TreeNode *> que{{root}}; !que.empty();) {
        const auto leader = que.front();
        que.pop();
        if (leader->left != nullptr) {
            que.push(leader->left);
        }
        if (leader->right != nullptr) {
            que.push(leader->right);
        }
        if (isSubPathRec(head, leader)) {
            return true;
        }
    }
    return false;
}


}
