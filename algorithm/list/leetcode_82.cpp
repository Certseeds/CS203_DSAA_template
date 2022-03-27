// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_82_test.hpp"

namespace leetcode_82 {
ListNode *leetcode_82::deleteDuplicates(ListNode *head) {
    ListNode will_return(-1);
    ListNode *will_return_ptr = &will_return;
    while (head != nullptr) {
        ListNode *const head_back{head};
        size_t count{0};
        for (int32_t v = head->val; head != nullptr && head->val == v; head = head->next) {
            count++;
        }
        if (count == 1) {
            will_return_ptr->next = head_back;
            will_return_ptr = will_return_ptr->next;
        }
    }
    will_return_ptr->next = nullptr;
    return will_return.next;
}
}

