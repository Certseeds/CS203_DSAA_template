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
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <ListNode.hpp>

namespace leetcode_21 {
using LISTNODE::ListNode;
using std::unordered_map;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_21 {
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test_21]", "[test_21]") {
    const ListNodeLink vec1{1, 2, 4};
    const ListNodeLink vec2{1, 3, 4};
    const ListNode *const node1 = leetcode_21::mergeTwoLists(vec1[0], vec2[0]);
    CHECK(ListNode::equal({1, 1, 2, 3, 4, 4}, node1));
}

TEST_CASE("2 [test_21]", "[test_21]") {
    const ListNodeLink vec1{1, 1, 1, 4, 4, 5};
    const ListNodeLink vec2{0, 1, 1, 1, 8, 9, 9};
    const ListNode *const node1 = leetcode_21::mergeTwoLists(vec1[0], vec2[0]);
    CHECK(ListNode::equal({0, 1, 1, 1, 1, 1, 1, 4, 4, 5, 8, 9, 9}, node1));
}

TEST_CASE("3 [test_21]", "[test_21]") {
    const ListNode *const node1 = leetcode_21::mergeTwoLists(nullptr, nullptr);
    CHECK(ListNode::equal({}, node1));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_HPP