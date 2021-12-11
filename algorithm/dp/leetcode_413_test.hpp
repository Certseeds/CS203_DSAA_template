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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_413 {
using std::vector;

struct leetcode_413 final {
    static int32_t numberOfArithmeticSlices(const vector<int32_t> &nums);
};


TEST_CASE("1 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto output{3};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("2 [test_413]", "[test_413]") {
    const vector<int32_t> input{1};
    static constexpr const auto output{0};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("3 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 8, 9, 10};
    static constexpr const auto output{2};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("4 [test_413]", "[test_413]") {
    const vector<int32_t> input{2, 1, 3, 4, 2, 3};
    static constexpr const auto output{0};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
