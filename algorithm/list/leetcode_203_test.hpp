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
//@Plan 数据结构入门 Day7

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>

namespace leetcode_203 {
using LISTNODE::ListNode;

struct leetcode_203 final : private nonCopyMoveAble {
    static ListNode *removeElements(ListNode *head, int32_t val);
};

TEST_CASE("test case 1 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{1, 2, 6, 3, 4, 5, 6};
    static constexpr const auto remove{6};
    const vector<int32_t> output{1, 2, 3, 4, 5};
    const ListNode *const result = leetcode_203::removeElements(vec1[0], remove);
    CHECK(ListNode::equal(output, result));
}

TEST_CASE("test case 2 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{6, 6, 6, 5, 6, 9, 3, 4, 5, 6};
    static constexpr const auto remove{6};
    const vector<int32_t> output{5, 9, 3, 4, 5};
    const ListNode *const result = leetcode_203::removeElements(vec1[0], remove);
    CHECK(ListNode::equal(output, result));
}

TEST_CASE("test case 3 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{6, 6, 6, 6, 6};
    static constexpr const auto remove{6};
    const ListNode *const result = leetcode_203::removeElements(vec1[0], remove);
    CHECK(nullptr == result);
}

TEST_CASE("test case 4 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{};
    static constexpr const auto remove{114514};
    const ListNode *const result = leetcode_203::removeElements(vec1[0], remove);
    CHECK(nullptr == result);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP
