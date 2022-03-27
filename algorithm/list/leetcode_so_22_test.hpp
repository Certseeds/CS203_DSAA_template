// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day11

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_so_22 {

using LISTNODE::ListNode;

struct leetcode_so_22 final : private nonCopyMoveAble {
    static ListNode *getKthFromEnd(ListNode *head, int32_t k);
};

using LISTNODE::ListNodeLink;
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1};
    const auto result = leetcode_so_22::getKthFromEnd(vec1[0], 1);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("test case 2 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{4, 5, 1, 9};
    const auto result = leetcode_so_22::getKthFromEnd(vec1[0], 3);
    CHECK(ListNode::equal({5, 1, 9}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP
