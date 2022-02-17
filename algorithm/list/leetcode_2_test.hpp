/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
