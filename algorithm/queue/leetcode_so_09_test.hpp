/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
//@Tag Queue
//@Tag 队列
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_HPP

#include <catch_main.hpp>
#include <stack>
#include <string>

namespace leetcode_so_09 {
using std::stack;
using std::string;

struct CQueue {
    CQueue() = default;

    virtual void appendTail(int32_t value) = 0;

    virtual int deleteHead() = 0;

    virtual ~CQueue() = default;
};

struct leetcode_so_09 {
    static CQueue *pure();

    static CQueue *effective();
};

TEST_CASE("test case pure-1 [test_sw_09]", "[test_sw_09]") {
    std::function<CQueue *()> lambda;
    SECTION("pure") {
        lambda = leetcode_so_09::pure;
    }SECTION("effective") {
        lambda = leetcode_so_09::effective;
    }
    const auto ptr = std::unique_ptr<CQueue>(lambda());
    ptr->appendTail(3);
    CHECK(3 == ptr->deleteHead());
    CHECK(-1 == ptr->deleteHead());
}

TEST_CASE("test case pure-2 [test_sw_09]", "[test_sw_09]") {
    std::function<CQueue *()> lambda;
    SECTION("pure") {
        lambda = leetcode_so_09::pure;
    }SECTION("effective") {
        lambda = leetcode_so_09::effective;
    }
    const auto ptr = std::unique_ptr<CQueue>(lambda());
    CHECK(-1 == ptr->deleteHead());
    ptr->appendTail(5);
    ptr->appendTail(2);
    CHECK(5 == ptr->deleteHead());
    CHECK(2 == ptr->deleteHead());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_HPP
