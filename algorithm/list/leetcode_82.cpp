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
#include "leetcode_82_test.hpp"

namespace leetcode_82 {
ListNode *leetcode_82::deleteDuplicates(ListNode *head) {
    ListNode will_return(-1);
    ListNode *will_return_ptr = &will_return;
    while (head != nullptr) {
        ListNode *const head_back{head};
        size_t count{0};
        for (int32_t v = head->val; head != nullptr && head->val == v; head = head->next) {
            count++;
        }
        if (count == 1) {
            will_return_ptr->next = head_back;
            will_return_ptr = will_return_ptr->next;
        }
    }
    will_return_ptr->next = nullptr;
    return will_return.next;
}
}

