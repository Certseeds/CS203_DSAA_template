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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_HPP

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_HPP
