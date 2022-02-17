/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_743 {
using std::vector;

struct leetcode_743 {
    static int32_t networkDelayTime(const vector<vector<int32_t>> &times, int32_t n, int32_t k);
};

TEST_CASE("basic tests [test_743]", "[test_743]") {
    const vector<vector<int32_t>> input{
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
    };
    static constexpr const auto n{4}, k{2};
    static constexpr const auto result{2};
    CHECK(result == leetcode_743::networkDelayTime(input, n, k));
}

TEST_CASE("basic tests 2[test_743]", "[test_743]") {
    const vector<vector<int32_t>> input{
            {1, 2, 1},
    };
    static constexpr const auto n{2}, k{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_743::networkDelayTime(input, n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP
