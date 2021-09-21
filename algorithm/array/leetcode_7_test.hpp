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
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_HPP

#include <catch_main.hpp>
#include <array>
#include <vector>
#include <limits>

namespace leetcode_7 {
using std::array;
using std::vector;

struct leetcode_7 {
    static int32_t reverse(int32_t x);

    static int32_t reverse2(int32_t x);

    static int32_t reverse3(int32_t x);
};

TEST_CASE("1 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(123) == 321);
    CHECK(leetcode_7::reverse2(123) == 321);
    CHECK(leetcode_7::reverse3(123) == 321);
}

TEST_CASE("2 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(-123) == -321);
    CHECK(leetcode_7::reverse2(-123) == -321);
    CHECK(leetcode_7::reverse3(-123) == -321);
}

TEST_CASE("3 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(120) == 21);
    CHECK(leetcode_7::reverse2(120) == 21);
    CHECK(leetcode_7::reverse3(120) == 21);
}

TEST_CASE("4 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(0) == 0);
    CHECK(leetcode_7::reverse2(0) == 0);
    CHECK(leetcode_7::reverse3(0) == 0);
}

TEST_CASE("5 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(-2147483648) == 0);
    CHECK(leetcode_7::reverse2(-2147483648) == 0);
    CHECK(leetcode_7::reverse3(-2147483648) == 0);
}

TEST_CASE("6 [test 7]", "[test 7]") {
    CHECK(leetcode_7::reverse(1463847412) == 2147483641);
    CHECK(leetcode_7::reverse2(1463847412) == 2147483641);
    CHECK(leetcode_7::reverse3(1463847412) == 2147483641);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_HPP
