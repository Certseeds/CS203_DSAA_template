// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_236_test.hpp"
#include <unordered_map>

namespace leetcode_236 {
using std::unordered_map;

bool nodeHadValue(unordered_map<TreeNode *, uint8_t> &umap, TreeNode *base, int32_t value) {
    if (base == nullptr) {
        return false;
    }
    if (umap.count(base) != 0) {
        return umap.at(base);
    }
    if (base->val == value) {
        umap[base] = true;
        return true;
    }
    const auto will_return = nodeHadValue(umap, base->left, value) || nodeHadValue(umap, base->right, value);
    umap[base] = will_return;
    return will_return;
}

const TreeNode *
leetcode_236::lowestCommonAncestor(const TreeNode *root, const TreeNode *const p, const TreeNode *const q) {
    if (root == nullptr) {
        return nullptr;
    }
    for (unordered_map<TreeNode *, uint8_t> pmap, qmap; root != nullptr;) {
        if (root->val == p->val) {
            return p;
        } else if (root->val == q->val) {
            return q;
        }
        const auto pleft = nodeHadValue(pmap, root->left, p->val);
        const auto pright = nodeHadValue(pmap, root->right, p->val);

        const auto qleft = nodeHadValue(qmap, root->left, q->val);
        const auto qright = nodeHadValue(qmap, root->right, q->val);
        if (pleft && qright) {
            return root;
        } else if (pright && qleft) {
            return root;
        } else if (pleft && qleft) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return nullptr;
}

}