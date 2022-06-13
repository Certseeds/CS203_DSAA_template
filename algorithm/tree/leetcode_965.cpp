// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_965_test.hpp"
#include <stack>

namespace leetcode_965 {
using std::stack;

bool leetcode_965::isUnivalTreeRec(TreeNode *root) {
    for (stack<TreeNode const *> sta{{root}}; !sta.empty();) {
        const TreeNode *now = sta.top();
        sta.pop();
        const auto lambda = [now, &sta](TreeNode const *son) {
            if (son != nullptr) {
                if (now->val != son->val) {
                    return false;
                }
                sta.push(son);
            }
            return true;
        };
        if (!lambda(now->left) || !lambda(now->right)) {
            return false;
        }
    }
    return true;
}

bool leetcode_965::isUnivalTreeIter(TreeNode *root) {
    const std::function<bool(TreeNode *const, int32_t)> judgement =
            [&judgement](TreeNode *const root, int32_t value) {
                if (root == nullptr) {
                    return true;
                }
                return (
                        (root->val == value) &&
                        judgement(root->left, root->val) &&
                        judgement(root->right, root->val));
            };
    return judgement(root, root->val);
}
}