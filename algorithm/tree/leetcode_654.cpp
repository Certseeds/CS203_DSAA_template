// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
#include "leetcode_654_test.hpp"

namespace leetcode_654 {

inline int get_max(const vector<int> &nums, size_t begin, size_t end) {
    int maxv{INT16_MIN}, posi{0};
    for (size_t i{begin}; i < end; i++) {
        if (maxv < nums[i]) {
            maxv = nums[i];
            posi = i;
        }
    }
    return posi;
}

TreeNode *rec(const vector<int> &nums, size_t begin, size_t end) {
    //cout << begin << " " << end << endl;
    if (begin == end) {
        return nullptr;
    }
    const int posi = get_max(nums, begin, end);
    auto *const willreturn = new TreeNode(nums[posi]);
    willreturn->left = rec(nums, begin, posi);
    willreturn->right = rec(nums, posi + 1, end);
    return willreturn;
}

TreeNode *leetcode_654::constructMaximumBinaryTree(const vector<int32_t> &nums) {
    return rec(nums, 0, nums.size());
}

}
