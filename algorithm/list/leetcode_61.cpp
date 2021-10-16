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
#include "leetcode_61_test.hpp"

namespace leetcode_61 {
ListNode *leetcode_61::rotateRight(ListNode *head, int32_t k) {
    if (head == nullptr) {
        return nullptr;
    }
    int32_t node_size{0};
    for (const ListNode *count_node{head};
         count_node != nullptr;
         count_node = count_node->next) {
        node_size++;
    }
    k = k % node_size;
    ListNode *kth{head};
    for (int32_t count{0}; count < k && kth != nullptr; count++) {
        kth = kth->next;
    }
    if (kth == nullptr || k == 0) {
        return head;
    }
    ListNode *last_element{head};
    while (kth->next != nullptr) {
        kth = kth->next;
        last_element = last_element->next;
    }
    kth->next = head;
    auto *const will_return = last_element->next;
    last_element->next = nullptr;
    return will_return;
}
}

