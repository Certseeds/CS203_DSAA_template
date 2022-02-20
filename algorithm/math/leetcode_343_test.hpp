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
//@Tag Math
//@Tag 数学
//@Plan 动态规划入门 Day21
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_343 {

struct leetcode_343 {
    template<typename T>
    static T integerBreak(T n);
};

TEST_CASE("1 [test_343]", "[test_343]") {
    static constexpr const auto input{2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("2 [test_343]", "[test_343]") {
    static constexpr const auto input{10};
    static constexpr const auto result{36};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("3 [test_343]", "[test_343]") {
    static constexpr const auto input{45};
    static constexpr const auto result{14348907};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("4 [test_343]", "[test_343]") {
    static constexpr const int64_t input{114};
    static constexpr const int64_t result{1350851717672992089};
    CHECK(result == leetcode_343::integerBreak(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

