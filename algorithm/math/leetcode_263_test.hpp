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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_263 {

struct leetcode_263 {
    static bool isUgly(int32_t n);
};

TEST_CASE("1 [test_263]", "[test_263]") {
    static constexpr const auto input{6};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("2 [test_263]", "[test_263]") {
    static constexpr const auto input{8};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("3 [test_263]", "[test_263]") {
    static constexpr const auto input{14};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("4 [test_263]", "[test_263]") {
    static constexpr const auto input{1};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("5 [test_263]", "[test_263]") {
    static constexpr const auto input{-1};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("6 [test_263]", "[test_263]") {
    static constexpr const auto input{0};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("7 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::min()};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("8 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::max()};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("9 [test_263]", "[test_263]") {
    static constexpr const auto input{233};
    CHECK_FALSE(leetcode_263::isUgly(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

