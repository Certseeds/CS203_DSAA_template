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
//@Tag 优先队列
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_23 {
using LISTNODE::ListNode;

struct leetcode_23 {
    static ListNode *mergeKLists(const std::vector<ListNode *> &lists);
};

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test _23]", "[test _23]") {
    const ListNodeLink vec1{1, 4, 5};
    const ListNodeLink vec2{1, 3, 4};
    const ListNodeLink vec3{2, 6};
    const auto input = vector<ListNode *>{vec1[0], vec2[0], vec3[0]};
    const ListNode *const result = leetcode_23::mergeKLists(input);
    CHECK(ListNode::equal({1, 1, 2, 3, 4, 4, 5, 6}, result));
}

TEST_CASE("2 [test _23]", "[test _23]") {
    const auto input = vector<ListNode *>{};
    const ListNode *const result = leetcode_23::mergeKLists(input);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _23]", "[test _23]") {
    const auto input = vector<ListNode *>{nullptr};
    const ListNode *const result = leetcode_23::mergeKLists(input);
    CHECK(ListNode::equal({}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_HPP
