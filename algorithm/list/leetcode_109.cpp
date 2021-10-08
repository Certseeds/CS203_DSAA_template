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
#include "leetcode_109_test.hpp"

namespace leetcode_109 {


TreeNode *leetcode_109::sortedListToBST(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return new TreeNode(head->val);
    }
    ListNode *one{head}, *two{head}, *prev{nullptr};
    while (two->next != nullptr) {
        prev = one;
        one = one->next;
        two = two->next;
        if (two->next != nullptr) {
            two = two->next;
        }
    }
    auto *const mid = new TreeNode(one->val);
    prev->next = nullptr;
    mid->left = sortedListToBST(head);
    mid->right = sortedListToBST(one->next);
    return mid;
}

}

