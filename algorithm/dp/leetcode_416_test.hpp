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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_416 {
using std::vector;
using std::unordered_map;

struct leetcode_416 final {
    static bool canPartition(const vector<int32_t> &nums);

    static bool canPartition2(const vector<int32_t> &nums);
};


TEST_CASE("1 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 5, 11, 5};
    CHECK(leetcode_416::canPartition(input));
    CHECK(leetcode_416::canPartition2(input));
}

TEST_CASE("2 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 2, 3, 5};
    CHECK_FALSE(leetcode_416::canPartition(input));
    CHECK_FALSE(leetcode_416::canPartition2(input));
}

TEST_CASE("3 [test_416]", "[test_416]") {
    const vector<int32_t> input{114514};
    CHECK_FALSE(leetcode_416::canPartition(input));
    CHECK_FALSE(leetcode_416::canPartition2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
