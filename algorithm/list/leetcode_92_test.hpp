/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_HPP

#include <catch_main.hpp>
#include <ListNode.hpp>

namespace leetcode_92 {
using LISTNODE::ListNode;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

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
    const ListNodeLink vec1{3,5};
    const ListNode *const result = leetcode_92::reverseBetween(vec1[0], 1, 1);
    CHECK(ListNode::equal({3,5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_HPP
