// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_1315_test.hpp"

#include <stack>

namespace leetcode_1315 {

int32_t visit(const TreeNode *const pp, const TreeNode *const p, const TreeNode *const node) {
    if (node == nullptr) {
        return 0;
    }
    int32_t will_return{0};
    if (pp->val % 2 == 0) {
        will_return += node->val;
    }
    will_return += visit(p, node, node->left);
    will_return += visit(p, node, node->right);
    return will_return;
}

int32_t leetcode_1315::sumEvenGrandparentRec(TreeNode *root) {
    TreeNode ppNode{1}, pNode{1};
    ppNode.left = &pNode;
    pNode.left = root;
    const auto result = visit(&ppNode, &pNode, root);
    return result;
}

int32_t leetcode_1315::sumEvenGrandparentIter(TreeNode *root) {
    TreeNode ppNode{1}, pNode{1};
    ppNode.left = &pNode;
    pNode.left = root;
    int32_t will_return{0};
    for (std::stack<std::tuple<const TreeNode *const, const TreeNode *const, const TreeNode *const>> sta{
            {std::make_tuple(&ppNode, &pNode, root)}}; !sta.empty();) {
        const auto [pp, p, node] = sta.top();
        sta.pop();
        if (node == nullptr) {
            continue;
        }
        if (pp->val % 2 == 0) {
            will_return += node->val;
        }
        sta.push(std::make_tuple(p, node, node->left));
        sta.push(std::make_tuple(p, node, node->right));
    }
    return will_return;
}


}