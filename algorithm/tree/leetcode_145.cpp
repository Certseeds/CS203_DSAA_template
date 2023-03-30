// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_145_test.hpp"
#include "traverse.cpp"

namespace leetcode_145 {
using namespace Tree_Traverse;

vector<int32_t> leetcode_145::postorderTraversalIter(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    iter::post(root, function);
    return will_return;
}

vector<int32_t> leetcode_145::postorderTraversal(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    rec::post(root, function);
    return will_return;
}
}
