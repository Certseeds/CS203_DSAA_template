// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_19 {
using LISTNODE::ListNode;

struct leetcode_19 {
    static ListNode *removeNthFromEnd(ListNode *head, int32_t n);

    static ListNode *removeNthFromEnd2(ListNode *head, int32_t n);
};

using LISTNODE::ListNodeLink;

TEST_CASE("test case 1 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 2);
    CHECK(ListNode::equal({1, 2, 3, 5}, result));
}

TEST_CASE("test case 2 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4}, result));
}

TEST_CASE("test case 3 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd(vec1[0], 5);
    CHECK(ListNode::equal({2, 3, 4, 5}, result));
}

TEST_CASE("test case 2-1 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 2);
    CHECK(ListNode::equal({1, 2, 3, 5}, result));
}

TEST_CASE("test case 2-2 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4}, result));

}

TEST_CASE("test case 2-3 [test_19]", "[test_19]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto *const result = leetcode_19::removeNthFromEnd2(vec1[0], 5);
    CHECK(ListNode::equal({2, 3, 4, 5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_19_TEST_HPP
