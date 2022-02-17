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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_372 {

struct leetcode_372 {
    static int32_t superPow(int32_t a, const vector<int32_t> &b);
};

TEST_CASE("1 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2};
    const vector<int32_t> inputB{3};
    static constexpr const auto result{8};
    CHECK(result == leetcode_372::superPow(inputA, inputB));
}

TEST_CASE("2 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2};
    const vector<int32_t> inputB{1, 0};
    static constexpr const auto result{1024};
    CHECK(result == leetcode_372::superPow(inputA, inputB));
}

TEST_CASE("3 [test_372]", "[test_372]") {
    static constexpr const auto inputA{1};
    const vector<int32_t> inputB{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{1};
    CHECK(result == leetcode_372::superPow(inputA, inputB));
}

TEST_CASE("4 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2147483647};
    const vector<int32_t> inputB{2, 0, 0};
    static constexpr const auto result{1198};
    CHECK(result == leetcode_372::superPow(inputA, inputB));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP

