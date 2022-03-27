// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_94_test.hpp"
#include "traverse.cpp"

namespace leetcode_94 {
using namespace Tree_Traverse;

vector<int32_t> leetcode_94::inorderTraversalIter(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    iter::in(root, function);
    return will_return;
}

vector<int32_t> leetcode_94::inorderTraversal(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    rec::in(root, function);
    return will_return;
}
}