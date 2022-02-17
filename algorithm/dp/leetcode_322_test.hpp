/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_322_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_322_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_322 {
using std::vector;

struct leetcode_322 final {
    static int32_t coinChange(const vector<int32_t> &coins, int32_t amount);
};

TEST_CASE("1 [test_322]", "[test_322]") {
    const vector<int32_t> input{1, 2, 5};
    static constexpr const auto amount{11};
    static constexpr const auto result{3};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

TEST_CASE("2 [test_322]", "[test_322]") {
    const vector<int32_t> input{2};
    static constexpr const auto amount{3};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

TEST_CASE("3 [test_322]", "[test_322]") {
    const vector<int32_t> input{1};
    static constexpr const auto amount{0};
    static constexpr const auto result{0};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

TEST_CASE("4 [test_322]", "[test_322]") {
    const vector<int32_t> input{1};
    static constexpr const auto amount{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

TEST_CASE("5 [test_322]", "[test_322]") {
    const vector<int32_t> input{1};
    static constexpr const auto amount{2};
    static constexpr const auto result{2};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

TEST_CASE("6 [test_322]", "[test_322]") {
    const vector<int32_t> input{112, 149, 215, 496, 482, 436, 144, 397, 500, 189};
    static constexpr const auto amount{8480};
    static constexpr const auto result{17};
    CHECK(result == leetcode_322::coinChange(input, amount));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_322_TEST_CPP
