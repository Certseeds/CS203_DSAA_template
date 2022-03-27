// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_109_test.hpp"

namespace leetcode_109 {


TreeNode *leetcode_109::sortedListToBST(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return new TreeNode(head->val);
    }
    ListNode *one{head}, *two{head}, *prev{nullptr};
    while (two->next != nullptr) {
        prev = one;
        one = one->next;
        two = two->next;
        if (two->next != nullptr) {
            two = two->next;
        }
    }
    auto *const mid = new TreeNode(one->val);
    prev->next = nullptr;
    mid->left = sortedListToBST(head);
    mid->right = sortedListToBST(one->next);
    return mid;
}

}

