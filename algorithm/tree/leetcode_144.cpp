// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_144_test.hpp"
#include "traverse.cpp"

namespace leetcode_144 {
using namespace Tree_Traverse;

vector<int32_t> leetcode_144::preorderTraversalIter(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    iter::pre1(root, function);
    return will_return;
}

vector<int32_t> leetcode_144::preorderTraversal(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    rec::pre(root, function);
    return will_return;
}
}