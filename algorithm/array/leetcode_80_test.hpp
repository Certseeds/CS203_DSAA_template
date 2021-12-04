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
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <vector>

namespace leetcode_80 {
using std::vector;

struct leetcode_80 {
    static int32_t removeDuplicates(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_80]", "[test_80]") {
    vector<int32_t> input{0, 0, 1, 1, 1, 1, 2, 3, 3};
    const vector<int32_t> result{0, 0, 1, 1, 2, 3, 3};
    const auto size = leetcode_80::removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}

TEST_CASE("2 [test_80]", "[test_80]") {
    vector<int32_t> input{1, 1, 1, 2, 2, 3};
    const vector<int32_t> result{1, 1, 2, 2, 3};
    const auto size = leetcode_80::removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_HPP
