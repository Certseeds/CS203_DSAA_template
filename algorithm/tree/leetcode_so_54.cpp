// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_so_54_test.hpp"
#include "traverse.cpp"

namespace leetcode_so_54 {
using namespace Tree_Traverse;

int32_t leetcode_so_54::kthLargest(TreeNode *root, int32_t k) {
    vector<int32_t> countVec;
    const auto functionPre = [&countVec](const TreeNode *tn) -> void {
        countVec.push_back(tn->val);
    };
    iter::in(root, functionPre);
    const auto netElements = countVec.size();
    vector<int32_t> element;
    static size_t count{0};
    const auto function = [&element, k, netElements](const TreeNode *tn) -> void {
        ++count;
        if (count + k == netElements + 1) { element.push_back(tn->val); }
    };
    iter::in(root, function);
    count = 0;
    return element.front();
}

}
