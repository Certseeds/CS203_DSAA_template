// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day02
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_24_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_24_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_24 {
using LISTNODE::ListNode;

struct leetcode_24 {
    static ListNode *swapPairs(ListNode *head);
};

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test _24]", "[test _24]") {
    const ListNodeLink vec1{1, 2, 3, 4};
    const ListNode *const result = leetcode_24::swapPairs(vec1[0]);
    CHECK(ListNode::equal({2, 1, 4, 3}, result));

}

TEST_CASE("2 [test _24]", "[test _24]") {
    const ListNode *const result = leetcode_24::swapPairs(nullptr);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _24]", "[test _24]") {
    const ListNodeLink vec1{1};
    const ListNode *const result = leetcode_24::swapPairs(vec1[0]);
    CHECK(ListNode::equal({1}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_24_TEST_HPP
