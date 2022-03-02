// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_86_test.hpp"

namespace leetcode_86 {

ListNode *leetcode_86::partition(ListNode *head, int32_t x) {
    ListNode node1{-1}, node2{-1};
    ListNode *p_node1{&node1}, *p_node2{&node2};
    while (head != nullptr) {
        if (head->val >= x) {
            p_node2->next = new ListNode(head->val);
            p_node2 = p_node2->next;
        } else {
            p_node1->next = new ListNode(head->val);
            p_node1 = p_node1->next;
        }
        head = head->next;
    }
    p_node1->next = node2.next;
    return node1.next;
}

}

