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
