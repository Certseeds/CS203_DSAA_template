// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Plan 数据结构入门 Day9
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>

namespace leetcode_232 {

struct leetcode_232 {
    class MyQueue {
    public:
        MyQueue() = default;

        virtual void push(int x) = 0;

        virtual int pop() = 0;

        virtual int peek() = 0;

        virtual bool empty() const = 0;

        virtual ~MyQueue() = default;
    };

    static MyQueue *pure();
};

TEST_CASE("1 [test_232]", "[test_232]") {
    const auto pointer = std::unique_ptr<leetcode_232::MyQueue>(leetcode_232::pure());
    CHECK(pointer->empty());
    pointer->push(1);
    pointer->push(2);
    CHECK(1 == pointer->peek());
    CHECK(1 == pointer->pop());
    CHECK_FALSE(pointer->empty());
    CHECK(2 == pointer->peek());
    CHECK(2 == pointer->pop());
    CHECK(pointer->empty());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP
