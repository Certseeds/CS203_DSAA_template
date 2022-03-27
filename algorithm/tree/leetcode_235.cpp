// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_235_test.hpp"
#include "traverse.cpp"

namespace leetcode_235 {
using namespace Tree_Traverse;

bool leetcode_235::findTarget(TreeNode *root, int k) {
    vector<int32_t> targets{};
    const auto func = [&targets](const TreeNode *tn) -> void { targets.push_back(tn->val); };
    iter::in(root, func);
    for (size_t ll{0}, rr{targets.size() - 1}; ll < rr;) {
        const auto sum = targets[ll] + targets[rr];
        if (sum == k) {
            return true;
        } else if (sum > k) {
            --rr;
        } else if (sum < k) {
            ++ll;
        }
    }
    return false;
}
}