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
#include "leetcode_19_test.hpp"

namespace leetcode_19 {
ListNode * leetcode_19::removeNthFromEnd(ListNode *head, int32_t n) {
    // auto *will_return = new ListNode(0);
    ListNode will_return_o{0,head};
    auto *const will_return = &will_return_o;
    ListNode *first = will_return;
    ListNode *second = will_return;
    if (n == 0) {
        second = second->next;
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        first->next = nullptr;
        return head;
    }
    for (int32_t i{0}; i <= n; i++) {
        second = second->next;
    }
    while (second != nullptr) {
        first = first->next;
        second = second->next;
    }
    if (first == nullptr || first->next == nullptr) {
        return head;
    }
    first->next = (first->next)->next;
    return will_return->next;
}

ListNode * leetcode_19::removeNthFromEnd2(ListNode *head, int32_t n) {
    // auto *will_return = new ListNode(0);
    ListNode will_return_o{0,head};
    auto *const will_return = &will_return_o;
    ListNode *first = will_return;
    ListNode *second = will_return;
    for (int32_t i{0}; i <= n; i++) {
        second = second->next;
    }
    while (second != nullptr) {
        first = first->next;
        second = second->next;
    }
    if (first == nullptr || first->next == nullptr) {
        return head;
    }
    first->next = (first->next)->next;
    return will_return->next;
}

}