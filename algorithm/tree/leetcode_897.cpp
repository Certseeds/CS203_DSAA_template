// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_897_test.hpp"
#include <queue>

namespace leetcode_897 {
using std::queue;

void getSon(TreeNode *const root, queue<TreeNode *> &pq) {
    if (pq.empty()) {
        return;
    }
    root->left = nullptr;
    root->right = pq.front();
    pq.pop();
    getSon(root->right, pq);
}

void rec(TreeNode *const root, queue<TreeNode *> &pq) {
    if (root == nullptr) {
        return;
    }
    rec(root->left, pq);
    pq.push(root);
    rec(root->right, pq);
}


TreeNode *leetcode_897::increasingBST(TreeNode *root) {
    queue<TreeNode *> pq;
    rec(root, pq);
    auto *const rooted = pq.front();
    pq.pop();
    getSon(rooted, pq);
    return rooted;
}
}
