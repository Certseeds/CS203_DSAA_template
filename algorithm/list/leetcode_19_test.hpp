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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <ListNode.hpp>

namespace leetcode_19 {
using LISTNODE::ListNode;
using std::unordered_map;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_19 {
    static ListNode *removeNthFromEnd(ListNode *head, int32_t n);
    static ListNode *removeNthFromEnd2(ListNode *head, int32_t n);
};

using LISTNODE::ListNodeLink;

TEST_CASE("test case 1 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 2);
    CHECK(ListNode::equal({1, 2, 3, 5}, result));
}

TEST_CASE("test case 2 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4}, result));
}

TEST_CASE("test case 3 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 5);
    CHECK(ListNode::equal({2, 3, 4, 5}, result));
}
TEST_CASE("test case 2-1 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 2);
    CHECK(ListNode::equal({1, 2, 3, 5}, result));
}

TEST_CASE("test case 2-2 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4}, result));

}

TEST_CASE("test case 2-3 [test 19]", "[test 19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 5);
    CHECK(ListNode::equal({2, 3, 4, 5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_HPP
