// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag list
//@Tag 链表
//@Tag
//@Description 利用地址不重复
//@Plan 数据结构入门 Day7

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_141 {
using LISTNODE::ListNode;

struct leetcode_141 {
    static bool hasCycle(ListNode *head);

    static bool hasCycle2(ListNode *head);
};

using LISTNODE::ListNodeLink;

TEST_CASE("fst [test_141]", "[test_141]") {
    const ListNodeLink link{3, 2, 0, -4};
    link[3]->next = link[1];
    CHECK(leetcode_141::hasCycle(link[0]));
    CHECK(leetcode_141::hasCycle2(link[0]));
}

TEST_CASE("2nd [test_141]", "[test_141]") {
    const ListNodeLink link{1, 2};
    link[1]->next = link[0];
    CHECK(leetcode_141::hasCycle(link[0]));
    CHECK(leetcode_141::hasCycle2(link[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_141_TEST_HPP
