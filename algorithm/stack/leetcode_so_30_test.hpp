/*
MIT License

CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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
//@Tag stack
//@Tag 栈
//@Plan 剑指OfferII-I Day01
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP

#include <catch_main.hpp>

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
