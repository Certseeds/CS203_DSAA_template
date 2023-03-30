// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_so_06_test.hpp"
#include <stack>

namespace leetcode_so_06 {

vector<int> leetcode_so_06::reversePrint(ListNode *head) {
    std::stack<int32_t> sta;
    while (head != nullptr) {
        sta.push(head->val);
        head = head->next;
    }
    vector<int32_t> will_return;
    while (!sta.empty()) {
        will_return.push_back(sta.top());
        sta.pop();
    }
    return will_return;
}

}
