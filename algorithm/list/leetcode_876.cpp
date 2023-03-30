// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_876_test.hpp"

namespace leetcode_876 {

ListNode *leetcode_876::middleNode(ListNode *const head) {
    ListNode *one = head;
    for (const ListNode *two = head; two != nullptr;) {
        if (two->next != nullptr) {
            two = two->next;
        } else {
            return one;
        }
        two = two->next;
        one = one->next;
    }
    return one;
}

}
