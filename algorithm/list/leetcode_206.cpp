/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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