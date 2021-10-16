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
#include "leetcode_25_test.hpp"

namespace leetcode_25 {

ListNode *leetcode_25::reverseKGroup(ListNode *head, int32_t k) {
    if (head == nullptr) {
        return head;
    }
    vector<ListNode *> nodes;
    for (int32_t i{0}; i < k && head != nullptr; ++i) {
        nodes.push_back(head);
        head = head->next;
    }
    const auto nodes_size = static_cast<int32_t>(nodes.size());
    if (nodes_size != k) {
        return nodes.front();
    }
    ListNode *const knext = reverseKGroup(nodes.back()->next, k);
    for (int32_t i{0}; i < nodes_size - 1; i++) {
        nodes[i + 1]->next = nodes[i];
    }
    nodes[0]->next = knext;
    return nodes.back();
}

}

