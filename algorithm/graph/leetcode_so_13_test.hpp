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
//@Tag DFS
//@Tag 深度优先遍历
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_so_13 {

struct leetcode_so_13 {
    static int32_t movingCount(int32_t m, int32_t n, int32_t k);
};

TEST_CASE("basic tests [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{2}, n{3}, k{1};
    static constexpr const auto result{3};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}

TEST_CASE("basic tests 2 [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{3}, n{1}, k{0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}

TEST_CASE("basic tests 3 [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{1}, n{2}, k{1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP
