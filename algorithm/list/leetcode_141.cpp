/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_141_test.hpp"
#include <unordered_set>
// 无需畏惧死循环, while这个肯定能打破

namespace leetcode_141 {
using std::unordered_set;

bool leetcode_141::hasCycle(ListNode *head) {
    for (unordered_set<ListNode *> nodes{}; head != nullptr;) {
        if (nodes.count(head) != 0) {
            return true;
        }
        nodes.insert(head);
        head = head->next;
    }
    return false;
}

bool leetcode_141::hasCycle2(ListNode *head) {
    for (ListNode *quick{head}, *slow{head}; quick != nullptr && slow != nullptr;) {
        slow = slow->next;
        quick = quick->next;
        if (quick == nullptr) {
            return false;
        }
        quick = quick->next;
        if (slow == quick && slow != nullptr) {
            return true;
        }
    }
    return false;
}

}

