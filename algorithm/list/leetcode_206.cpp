// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_206_test.hpp"

namespace leetcode_206 {

/**
 * 第一版
 * */
ListNode *leetcode_206::reverseList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *ll = head;
    ListNode *rl = head->next;
    ListNode *rr = rl->next;
    while (rr != nullptr) {
        head->next = rr;
        rl->next = ll;
        ll = rl;
        rl = rr;
        rr = rr->next;
    }
    head->next = nullptr;
    rl->next = ll;
    ll = rl;
    return ll;
}

/**
 * 化简版
 * */
ListNode *leetcode_206::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *ll = head;
    ListNode *rl = head->next;
    while (rl != nullptr) {
        ListNode *rr = rl->next;
        head->next = rr;
        rl->next = ll;
        ll = rl;
        rl = rr;
    }
    return ll;
}
}
