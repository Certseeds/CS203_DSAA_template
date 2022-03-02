// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag Queue
//@Tag 队列
//@Tag 模拟
//@Plan 剑指OfferII-I Day01
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include <functional>
#include <memory>

namespace leetcode_so_09 {
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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP
