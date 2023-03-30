// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_617_test.hpp"
#include "traverse.cpp"

namespace leetcode_617 {
using namespace Tree_Traverse;

int32_t returnValueOfNode(TreeNode *t1, TreeNode *t2) {
    int willreturn{0};
    for (const auto i: {t1, t2}) {
        if (i != nullptr) {
            willreturn += i->val;
        }
    }
    return willreturn;
}

TreeNode *mergeTreesRec(TreeNode *t1, TreeNode *t2, const std::function<void(TreeNode *)> &func) {
    if (t1 == nullptr) {
        return t2;
    } else if (t2 == nullptr) {
        return t1;
    }
    auto *const willreturn = new TreeNode{returnValueOfNode(t1, t2)};
    func(willreturn);
    //cout << willreturn->val << endl;
    willreturn->left = mergeTreesRec(t1->left, t2->left, func);
    willreturn->right = mergeTreesRec(t1->right, t2->right, func);
    return willreturn;
}

std::pair<TreeNode *, vector<TreeNode *>> leetcode_617::mergeTrees(TreeNode *t1, TreeNode *t2) {
    vector<TreeNode *> will_return{};
    const auto func = [&will_return](TreeNode *node) { will_return.push_back(node); };
    const auto result = mergeTreesRec(t1, t2, func);
    return {result, will_return};
}


}
