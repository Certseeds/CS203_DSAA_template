// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_100_test.hpp"

namespace leetcode_100 {

bool leetcode_100::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == q) {
        return true;
    } else if (p == nullptr || q == nullptr) {
        return false;
    }
    return p->val == q->val &&
           isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
}