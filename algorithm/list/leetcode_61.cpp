// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_61_test.hpp"

namespace leetcode_61 {
ListNode *leetcode_61::rotateRight(ListNode *head, int32_t k) {
    if (head == nullptr) {
        return nullptr;
    }
    int32_t node_size{0};
    for (const ListNode *count_node{head};
         count_node != nullptr;
         count_node = count_node->next) {
        node_size++;
    }
    k = k % node_size;
    ListNode *kth{head};
    for (int32_t count{0}; count < k && kth != nullptr; count++) {
        kth = kth->next;
    }
    if (kth == nullptr || k == 0) {
        return head;
    }
    ListNode *last_element{head};
    while (kth->next != nullptr) {
        kth = kth->next;
        last_element = last_element->next;
    }
    kth->next = head;
    auto *const will_return = last_element->next;
    last_element->next = nullptr;
    return will_return;
}
}

