/*
MIT License

CS160_DSAA_template

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
#include "leetcode_160_test.hpp"

namespace leetcode_160 {

ListNode *leetcode_160::getIntersectionNode(ListNode *headA, ListNode *headB) {
    size_t aSize{0}, bSize{0};
    for (ListNode *temp{headA}; temp != nullptr; temp = temp->next, ++aSize) {}
    for (ListNode *temp{headB}; temp != nullptr; temp = temp->next, ++bSize) {}
    if (aSize > bSize) {
        for (size_t i{bSize}; i < aSize; ++i, headA = headA->next) {}
    } else if (aSize < bSize) {
        for (size_t i{aSize}; i < bSize; ++i, headB = headB->next) {}
    }
    ListNode aObj{-1, headA}, bObj{-1, headB};
    for (headA = &aObj,headB = &bObj; headA != nullptr; headA = headA->next, headB = headB->next) {
        if (headA->next == headB->next) {
            return headA->next;
        }
    }
    return nullptr;
}

}