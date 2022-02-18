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
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day12
#ifndef CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP
#define CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_160 {
using LISTNODE::ListNode;

struct leetcode_160 final : private nonCopyMoveAble {
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};


using LISTNODE::ListNodeLink;

TEST_CASE("test case 1 [test_160]", "[test_160]") {
    const ListNodeLink vecCommon{8, 4, 5};
    const ListNodeLink vec1{4, 1};
    const ListNodeLink vec2{5, 0, 1};
    vec1[1]->next = vecCommon[0];
    vec2[2]->next = vecCommon[0];
    const vector<int32_t> output{8, 4, 5};
    const ListNode *const result = leetcode_160::getIntersectionNode(vec1[0], vec2[0]);
    CHECK(ListNode::equal(output, result));
}
TEST_CASE("test case 2 [test_160]", "[test_160]") {
    const ListNodeLink vecCommon{1};
    const vector<int32_t> output{1};
    const ListNode *const result = leetcode_160::getIntersectionNode(vecCommon[0], vecCommon[0]);
    CHECK(ListNode::equal(output, result));
}
}
#endif //CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP
