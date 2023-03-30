// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_95_test.hpp"

namespace leetcode_95 {
vector<TreeNode *> generateTrees_rec(int32_t left, int32_t right) {
    if (left > right) {
        return vector<TreeNode *>{nullptr};
    } else if (left == right) {
        return vector<TreeNode *>{new TreeNode(left)};
    }
    vector<TreeNode *> will_return;
    for (int i = left; i <= right; i++) {
        const auto temp = generateTrees_rec(left, i - 1);
        for (auto const &j: temp) {
            const auto temp2 = generateTrees_rec(i + 1, right);
            for (auto const &k: temp2) {
                const auto will_insert = new TreeNode(i);
                will_insert->left = j;
                will_insert->right = k;
                will_return.emplace_back(will_insert);
                //will_return.emplace_back(i,j,k);
            }
        }
    }
    return will_return;
}

vector<TreeNode *> leetcode_95::generateTrees(int32_t n) {
    if (n == 0) {
        return vector<TreeNode *>{};
    }
    return generateTrees_rec(1, n);
}

}
