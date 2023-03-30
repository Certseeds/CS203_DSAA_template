// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_19_test.hpp"

namespace leetcode_19 {
ListNode *leetcode_19::removeNthFromEnd(ListNode *head, int32_t n) {
    // auto *will_return = new ListNode(0);
    ListNode will_return_o{0, head};
    auto *const will_return = &will_return_o;
    ListNode *first = will_return;
    ListNode *second = will_return;
    if (n == 0) {
        second = second->next;
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        first->next = nullptr;
        return head;
    }
    for (int32_t i{0}; i <= n; i++) {
        second = second->next;
    }
    while (second != nullptr) {
        first = first->next;
        second = second->next;
    }
    if (first == nullptr || first->next == nullptr) {
        return head;
    }
    first->next = (first->next)->next;
    return will_return->next;
}

ListNode *leetcode_19::removeNthFromEnd2(ListNode *head, int32_t n) {
    // auto *will_return = new ListNode(0);
    ListNode will_return_o{0, head};
    auto *const will_return = &will_return_o;
    ListNode *first = will_return;
    ListNode *second = will_return;
    for (int32_t i{0}; i <= n; i++) {
        second = second->next;
    }
    while (second != nullptr) {
        first = first->next;
        second = second->next;
    }
    if (first == nullptr || first->next == nullptr) {
        return head;
    }
    first->next = (first->next)->next;
    return will_return->next;
}

}
