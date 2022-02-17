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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_268 {
using std::vector;

struct leetcode_268 {
    static int32_t missingNumber(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_268]", "[test_268]") {
    const vector<int32_t> input{3, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_268::missingNumber(input));
}

TEST_CASE("2 [test_268]", "[test_268]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_268::missingNumber(input));
}

TEST_CASE("3 [test_268]", "[test_268]") {
    const vector<int32_t> input{9, 6, 4, 2, 3, 5, 7, 0, 1};
    static constexpr const auto result{8};
    CHECK(result == leetcode_268::missingNumber(input));
}


TEST_CASE("4 [test_268]", "[test_268]") {
    const vector<int32_t> input{0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_268::missingNumber(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP

