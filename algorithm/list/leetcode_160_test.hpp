/*
AGPL-3.0-or-later License

CS160_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day12
#ifndef CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP
#define CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_160 {
using LISTNODE::ListNode;

struct leetcode_160 final : private nonCopyMoveAble {
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

using LISTNODE::ListNodeLink;

TEST_CASE("test case 1 [test_160]", "[test_160]") {
    const ListNodeLink vecCommon{8, 4, 5};
    const ListNodeLink vec1{4, 1};
    const ListNodeLink vec2{5, 0, 1};
    vec1[1]->next = vecCommon[0];
    vec2[2]->next = vecCommon[0];
    const vector<int32_t> output{8, 4, 5};
    const ListNode *const result = leetcode_160::getIntersectionNode(vec1[0], vec2[0]);
    CHECK(ListNode::equal(output, result));
}
TEST_CASE("test case 2 [test_160]", "[test_160]") {
    const ListNodeLink vecCommon{1};
    const vector<int32_t> output{1};
    const ListNode *const result = leetcode_160::getIntersectionNode(vecCommon[0], vecCommon[0]);
    CHECK(ListNode::equal(output, result));
}
}
#endif //CS160_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_160_TEST_HPP
