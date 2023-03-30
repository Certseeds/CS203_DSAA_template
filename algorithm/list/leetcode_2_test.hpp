// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_2 {
using LISTNODE::ListNode;

struct leetcode_2 {
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

using LISTNODE::ListNodeLink;

TEST_CASE("basic tests [test_2]", "[test_2]") {
    const ListNodeLink vec1{2, 4, 3}, vec2{5, 6, 4};
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({7, 0, 8}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};
}

TEST_CASE("basic tests 2 [test_2]", "[test_2]") {
    const ListNodeLink vec1{0}, vec2{0};
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({0}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};
}

TEST_CASE("basic tests 3 [test_2]", "[test_2]") {
    const ListNodeLink vec1{9, 9, 9, 9, 9, 9, 9}, vec2{9, 9, 9, 9};
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({8, 9, 9, 9, 0, 0, 0, 1}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};

}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP
