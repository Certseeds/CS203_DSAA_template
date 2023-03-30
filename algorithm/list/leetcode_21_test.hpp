// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 数据结构入门 Day7
//@Plan 剑指OfferII-I Day12
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_21 {
using LISTNODE::ListNode;

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP
