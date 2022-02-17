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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_29 {
struct leetcode_29 {
    static int divide(int dividend, int divisor);
};

TEST_CASE("1 [test _29]", "[test _29]") {
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), -1) == std::numeric_limits<int32_t>::max());
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), 1) == std::numeric_limits<int32_t>::min());
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), 2) == -1073741824);
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), -2) == 1073741824);
    CHECK(leetcode_29::divide(10, 3) == 3);
    CHECK(leetcode_29::divide(7, -3) == -2);
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()) == 1);
    CHECK(leetcode_29::divide(-1010369383, -2147483648) == 0);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_HPP
