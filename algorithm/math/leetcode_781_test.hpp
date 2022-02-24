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
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_781 {
using std::vector;

struct leetcode_781 {
    static int32_t numRabbits(const vector<int32_t> &answers);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 2};
    static constexpr const auto output{5};
    CHECK(output == leetcode_781::numRabbits(input));
}

TEST_CASE("2 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto output{15};
    CHECK(output == leetcode_781::numRabbits(input));
}

TEST_CASE("3 [test_781]", "[test_781]") {
    const vector<int32_t> input{10, 10, 10};
    static constexpr const auto output{11};
    CHECK(output == leetcode_781::numRabbits(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

