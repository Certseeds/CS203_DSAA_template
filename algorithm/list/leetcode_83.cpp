// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_83_test.hpp"

namespace leetcode_83 {

ListNode *leetcode_83::deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    head->next = deleteDuplicates(head->next);
    if (head->val == head->next->val) {
        head = head->next;
    }
    return head;
}
}

