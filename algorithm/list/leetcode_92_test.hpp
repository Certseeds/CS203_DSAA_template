// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_92 {
using LISTNODE::ListNode;

struct leetcode_92 {
    static ListNode *reverseBetween(ListNode *head, int32_t left, int32_t right);
};

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _92]", "[test _92]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_92::reverseBetween(vec1[0], 2, 4);
    CHECK(ListNode::equal({1, 4, 3, 2, 5}, result));
}

TEST_CASE("0 [test _92]", "[test _92]") {
    const ListNodeLink vec1{5};
    const ListNode *const result = leetcode_92::reverseBetween(vec1[0], 1, 1);
    CHECK(ListNode::equal({5}, result));
}

TEST_CASE("1 [test _92]", "[test _92]") {
    const ListNodeLink vec1{3, 5};
    const ListNode *const result = leetcode_92::reverseBetween(vec1[0], 1, 1);
    CHECK(ListNode::equal({3, 5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP
