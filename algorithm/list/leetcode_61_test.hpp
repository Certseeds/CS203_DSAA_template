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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_HPP

#include <catch_main.hpp>
#include <list/ListNode.hpp>

namespace leetcode_61 {
using LISTNODE::ListNode;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_61 {
    static ListNode *rotateRight(ListNode *head, int32_t k);
};


using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 0);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("0 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({1, 2}, result));
}

TEST_CASE("1 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({4, 5, 1, 2, 3}, result));
}

TEST_CASE("2 [test _61]", "[test _61]") {
    const ListNode *const result = leetcode_61::rotateRight(nullptr, 2);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 3);
    CHECK(ListNode::equal({3, 4, 5, 1, 2}, result));
}

TEST_CASE("5 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 4);
    CHECK(ListNode::equal({2, 3, 4, 5, 1}, result));
}

TEST_CASE("6 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_61::rotateRight(vec1[0], 1234);
    CHECK(ListNode::equal({2, 3, 4, 5, 1}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_HPP
