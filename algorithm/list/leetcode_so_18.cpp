// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_so_18_test.hpp"

namespace leetcode_so_18 {

ListNode *leetcode_so_18::deleteNode(ListNode *head, int32_t val) {
    ListNode base{-1};
    base.next = head;
    for (ListNode *root{&base}; root->next != nullptr; root = root->next) {
        if (root->next->val == val) {
            root->next = root->next->next;
            break;
        }
    }
    return base.next;
}
}
