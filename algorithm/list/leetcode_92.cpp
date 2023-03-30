// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_92_test.hpp"

namespace leetcode_92 {
ListNode *leetcode_92::reverseBetween(ListNode *head, int32_t left, int32_t right) {
    ListNode will_return{-1};
    will_return.next = head;
    ListNode *pre{&will_return};
    for (int32_t i{1}; i < left; i++) {
        pre = pre->next;
    }
    ListNode *iter{pre->next};

    for (int32_t i{left}; i < right; i++) {
        ListNode *next{iter->next};
        ListNode *const prenext = pre->next;
        iter->next = next->next;
        pre->next = next;
        next->next = prenext;
    }
    return will_return.next;
}
}

