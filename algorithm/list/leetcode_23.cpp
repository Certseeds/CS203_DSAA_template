/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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

