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
#include "leetcode_203_test.hpp"

namespace leetcode_203 {

ListNode *leetcode_203::removeElements(ListNode *head, int32_t val) {
    ListNode fst(0);
    for (ListNode *base{head}; base != nullptr; base = base->next) {
        if (base->val != val) {
            fst.next = base;
            break;
        }
    }
    if (fst.next == nullptr) {
        return nullptr;
    }
    for (ListNode *base{fst.next}; base->next != nullptr;) {
        ListNode *nnext{base->next};
        if (nnext->val == val) {
            base->next = nnext->next;
        } else {
            base = base->next;
        }
    }
    return fst.next; // should not reach there
}

}