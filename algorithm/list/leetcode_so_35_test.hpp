// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Description 深复制
//@Plan 剑指OfferII-I Day02
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_35_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_35_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_so_35 {
struct Node {
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int32_t _val) : val(_val), next(nullptr), random(nullptr) {}
};

struct leetcode_so_35 final : private nonCopyMoveAble {
    static Node *copyRandomList(Node *head);
};

TEST_CASE("test case 1 [test_206]", "[test_206]") {}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_35_TEST_HPP
