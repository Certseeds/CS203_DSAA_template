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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_198 {
using std::vector;
using std::unordered_map;

struct leetcode_198 final {
    static int64_t rob(const vector<int32_t> &nums);

    static int64_t rob2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}

TEST_CASE("2 [test_198]", "[test_198]") {
    const vector<int32_t> input{2, 7, 9, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(12)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}

TEST_CASE("3 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}
}
namespace leetcode_213 {
using std::vector;
using std::unordered_map;

struct leetcode_213 final {
    static int64_t rob(const vector<int32_t> &nums);

    static int64_t rob2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_213]", "[test_213]") {
    const vector<int32_t> input{2, 3, 2};
    static constexpr const auto output{static_cast<int64_t>(3)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}

TEST_CASE("2 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}

TEST_CASE("3 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP
