// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_25_test.hpp"

namespace leetcode_25 {

ListNode *leetcode_25::reverseKGroup(ListNode *head, int32_t k) {
    if (head == nullptr) {
        return head;
    }
    vector<ListNode *> nodes;
    for (int32_t i{0}; i < k && head != nullptr; ++i) {
        nodes.push_back(head);
        head = head->next;
    }
    const auto nodes_size = static_cast<int32_t>(nodes.size());
    if (nodes_size != k) {
        return nodes.front();
    }
    ListNode *const knext = reverseKGroup(nodes.back()->next, k);
    for (int32_t i{0}; i < nodes_size - 1; i++) {
        nodes[i + 1]->next = nodes[i];
    }
    nodes[0]->next = knext;
    return nodes.back();
}

}

