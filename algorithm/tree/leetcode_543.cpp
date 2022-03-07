// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_543_test.hpp"

namespace leetcode_543 {
int rec(TreeNode *base, int32_t num, std::shared_ptr<int32_t> max) {
    if (base == nullptr) {
        return num;
    }
    const auto left = rec(base->left, num, max);
    const auto right = rec(base->right, num, max);
    *max = std::max(*max, left + right);
    return std::max(left, right) + 1;
}

int32_t leetcode_543::diameterOfBinaryTree(TreeNode *root) {
    auto maxV = std::make_shared<int32_t>(0);
    rec(root, 0, maxV);
    return *maxV;
}

}