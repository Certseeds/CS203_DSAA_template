// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Plan 剑指OfferII-I Day01
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP

#include <catch_main.hpp>
#include <memory>

namespace leetcode_so_30 {

struct MinStack {
    MinStack() = default;;

    virtual void push(int x) = 0;

    virtual void pop() = 0;

    virtual int top() = 0;

    virtual int min() = 0;

    virtual ~MinStack() = default;
};

struct leetcode_so_30 {
    static MinStack *pure();

    static MinStack *effective();
};

TEST_CASE("test case pure-1 [test_sw_30]", "[test_sw_30]") {
    std::function<MinStack *()> lambda;
    SECTION("pure") {
        lambda = leetcode_so_30::pure;
    }SECTION("effective") {
        lambda = leetcode_so_30::effective;
    }
    const auto ptr = std::unique_ptr<MinStack>(lambda());
    ptr->push(0);
    ptr->push(1);
    ptr->push(0);
    CHECK(0 == ptr->min());
    ptr->pop();
    CHECK(0 == ptr->min());
}

TEST_CASE("test case pure-2 [test_sw_30]", "[test_sw_30]") {
    std::function<MinStack *()> lambda;
    SECTION("pure") {
        lambda = leetcode_so_30::pure;
    }SECTION("effective") {
        lambda = leetcode_so_30::effective;
    }
    const auto ptr = std::unique_ptr<MinStack>(lambda());
    ptr->push(-2);
    ptr->push(0);
    ptr->push(-1);
    CHECK(-2 == ptr->min());
    CHECK(-1 == ptr->top());
    ptr->pop();
    CHECK(-2 == ptr->min());
    CHECK(0 == ptr->top());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP
