// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_141_test.hpp"
#include <unordered_set>
// 无需畏惧死循环, while这个肯定能打破

namespace leetcode_141 {
using std::unordered_set;

bool leetcode_141::hasCycle(ListNode *head) {
    for (unordered_set<ListNode *> nodes{}; head != nullptr;) {
        if (nodes.count(head) != 0) {
            return true;
        }
        nodes.insert(head);
        head = head->next;
    }
    return false;
}

bool leetcode_141::hasCycle2(ListNode *head) {
    for (ListNode *quick{head}, *slow{head}; quick != nullptr && slow != nullptr;) {
        slow = slow->next;
        quick = quick->next;
        if (quick == nullptr) {
            return false;
        }
        quick = quick->next;
        if (slow == quick && slow != nullptr) {
            return true;
        }
    }
    return false;
}

}

