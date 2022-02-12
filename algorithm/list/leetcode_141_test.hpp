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
//@Tag list
//@Tag 链表
//@Tag
//@Description 利用地址不重复
//
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/ListNode.hpp>

namespace leetcode_141 {
using LISTNODE::ListNode;

struct leetcode_141 {
    static bool hasCycle(ListNode *head);

    static bool hasCycle2(ListNode *head);
};

using LISTNODE::ListNodeLink;

TEST_CASE("fst [test_141]", "[test_141]") {
    const ListNodeLink link{3, 2, 0, -4};
    link[3]->next = link[1];
    CHECK(leetcode_141::hasCycle(link[0]));
    CHECK(leetcode_141::hasCycle2(link[0]));
}

TEST_CASE("2nd [test_141]", "[test_141]") {
    const ListNodeLink link{1, 2};
    link[1]->next = link[0];
    CHECK(leetcode_141::hasCycle(link[0]));
    CHECK(leetcode_141::hasCycle2(link[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_HPP
