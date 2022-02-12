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

