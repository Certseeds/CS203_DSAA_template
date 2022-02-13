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
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_HPP

#include <catch_main.hpp>
#include <list/ListNode.hpp>

namespace leetcode_86 {
using LISTNODE::ListNode;

struct leetcode_86 {
    static ListNode *partition(ListNode *head, int32_t x);
};

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _86]", "[test _86]") {
    const ListNodeLink vec1{1, 4, 3, 2, 5, 2};
    const ListNode *const result = leetcode_86::partition(vec1[0], 3);
    CHECK(ListNode::equal({1, 2, 2, 4, 3, 5}, result));

    vector<ListNode *> nodes;
    for (ListNode *will_delete{const_cast<ListNode *>(result)}; will_delete != nullptr;) {
        nodes.push_back(will_delete);
        will_delete = will_delete->next;
    }
    const ListNodeLink removed{nodes};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_HPP
