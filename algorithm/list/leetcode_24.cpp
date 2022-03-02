// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_24_test.hpp"

namespace leetcode_24 {

ListNode *leetcode_24::swapPairs(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return head;
    }
    ListNode *const fir = head;
    ListNode *const sec = fir->next;
    ListNode *const third = swapPairs(sec->next);
    sec->next = fir;
    fir->next = third;
    return sec;
}

}

