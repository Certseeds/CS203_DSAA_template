// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_23_test.hpp"

#include <queue>

using std::priority_queue;
namespace leetcode_23 {

ListNode *leetcode_23::mergeKLists(const vector<ListNode *> &lists) {
    static constexpr auto cmp{
            [](const ListNode *const v1, const ListNode *const v2) {
                return v1->val > v2->val;
            }};
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq{cmp};
    for (auto &&ele: lists) {
        if (ele != nullptr) {
            pq.push(ele);
        }
    }
    ListNode head(0);
    for (ListNode *stable = &head; !pq.empty();) {
        stable->next = pq.top();
        pq.pop();
        stable = stable->next;
        if (stable->next != nullptr) {
            pq.push(stable->next);
        }
    }
    return head.next;
}

}

