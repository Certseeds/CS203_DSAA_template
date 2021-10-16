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
#include "leetcode_2_test.hpp"

namespace leetcode_2 {
int32_t get_depth(ListNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int32_t will_return = 0;
    while (node != nullptr) {
        will_return++;
        node = node->next;
    }
    return will_return;
}

ListNode *leetcode_2::addTwoNumbers(ListNode *l1_in, ListNode *l2_in) {
    ListNode *l1 = l1_in;
    ListNode *l2 = l2_in;
    if (get_depth(l2) > get_depth(l1)) {
        std::swap(l1, l2);
    }
    ListNode will_return{0};
    ListNode *head = &will_return;
    int32_t add_in = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int32_t sum = (l1->val + l2->val + add_in);
        head->next = new ListNode(sum % 10);
        add_in = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        head = head->next;
    }
    while (l1 != nullptr) {
        int32_t sum = (l1->val + add_in);
        head->next = new ListNode{sum % 10};
        add_in = sum / 10;
        l1 = l1->next;
        head = head->next;
    }
    if (add_in != 0) {
        head->next = new ListNode{add_in};
    }
    return will_return.next;
}


}