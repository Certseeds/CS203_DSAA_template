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
//@Plan 数据结构入门 Day8
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_83_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_83_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_83 {
using LISTNODE::ListNode;

struct leetcode_83 {
    static ListNode *deleteDuplicates(ListNode *head);
};

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("0 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1, 2};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2}, result));
}

TEST_CASE("1 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}

TEST_CASE("2 [test _83]", "[test _83]") {
    const ListNode *const result = leetcode_83::deleteDuplicates(nullptr);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1, 2, 2, 3, 4, 5};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}

TEST_CASE("5 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1, 2, 2, 3, 3, 4, 5};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}

TEST_CASE("6 [test _83]", "[test _83]") {
    const ListNodeLink vec1{1, 1, 2, 2, 3, 3, 4, 4, 5};
    const ListNode *const result = leetcode_83::deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_83_TEST_HPP
