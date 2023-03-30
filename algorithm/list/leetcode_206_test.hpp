// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Description 反转链表
//@Plan 数据结构入门 Day8
//@Plan 剑指OfferII-I Day02
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_206_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_206_TEST_HPP

#include <catch_main.hpp>
#include <list/listnode.hpp>

namespace leetcode_206 {
using LISTNODE::ListNode;

struct leetcode_206 final : private nonCopyMoveAble {
    static ListNode *reverseList(ListNode *head);

    static ListNode *reverseList2(ListNode *head);
};

TEST_CASE("test case 1 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1, 2, 3, 4, 5};
    const auto result = leetcode_206::reverseList(vec1[0]);
    CHECK(ListNode::equal({5, 4, 3, 2, 1}, result));
}

TEST_CASE("test case 2 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1, 1, 4, 5, 1, 4};
    const auto result = leetcode_206::reverseList(vec1[0]);
    CHECK(ListNode::equal({4, 1, 5, 4, 1, 1}, result));
}

TEST_CASE("test case 3 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1, 9, 1, 9, 8, 1, 0};
    const auto result = leetcode_206::reverseList(vec1[0]);
    CHECK(ListNode::equal({0, 1, 8, 9, 1, 9, 1}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_206_TEST_HPP
