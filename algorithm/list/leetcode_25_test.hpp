// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_25 {
using LISTNODE::ListNode;

struct leetcode_25 {
    static ListNode *reverseKGroup(ListNode *head, int32_t k);
};

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_25::reverseKGroup(vec1[0], 2);
    CHECK(ListNode::equal({2, 1, 4, 3, 5}, result));
}

TEST_CASE("2 [test _25]", "[test _25]") {
    const ListNode *const result = leetcode_25::reverseKGroup(nullptr, 2);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_25::reverseKGroup(vec1[0], 2);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_25::reverseKGroup(vec1[0], 3);
    CHECK(ListNode::equal({3, 2, 1, 4, 5}, result));
}

TEST_CASE("5 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_25::reverseKGroup(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP
