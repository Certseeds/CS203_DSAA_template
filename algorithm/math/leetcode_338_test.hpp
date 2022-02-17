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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_338 {
using std::vector;

struct leetcode_338 {
    static vector<int32_t> countBits(int32_t num);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_338]", "[test_338]") {
    static constexpr const auto input{0};
    const vector<int32_t> result{0};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}

TEST_CASE("2 [test_338]", "[test_338]") {
    static constexpr const auto input{1};
    const vector<int32_t> result{0, 1};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}

TEST_CASE("3 [test_338]", "[test_338]") {
    static constexpr const auto input{2};
    const vector<int32_t> result{0, 1, 1};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}

TEST_CASE("4 [test_338]", "[test_338]") {
    static constexpr const auto input{5};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}

TEST_CASE("5 [test_338]", "[test_338]") {
    static constexpr const auto input{33};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
                                 4, 4, 5, 1, 2};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}

TEST_CASE("6 [test_338]", "[test_338]") {
    static constexpr const auto input{63};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
                                 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
                                 4, 5, 4, 5, 5, 6};
    CHECK_THAT(result, Equals(leetcode_338::countBits(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP

