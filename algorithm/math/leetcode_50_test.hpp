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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_50 {
struct leetcode_50 {
    static double myPow(double x, int n);
};

using Catch::Approx;
static constexpr const auto epsilon{1e-3};

TEST_CASE("1 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2147483648};
    static constexpr const auto result{0.0};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("2 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{10};
    static constexpr const auto result{1024.0};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("3 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2};
    static constexpr const auto result{0.25};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("4 [test_50]", "[test_50]") {
    static constexpr const auto x{2.1};
    static constexpr const auto n{3};
    static constexpr const auto result{9.261};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
