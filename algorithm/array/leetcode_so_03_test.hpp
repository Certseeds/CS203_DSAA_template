/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_so_03 {
using std::vector;

struct leetcode_so_03 {
    static int32_t findRepeatNumber(const vector<int32_t> &nums);

    static int32_t findRepeatNumber2(const vector<int32_t> &nums);

    static int32_t findRepeatNumber3(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_so_03]", "[test_so_03]") {
    const vector<int32_t> input{1, 2, 2, 3, 1};
    static constexpr const auto resultOne{1}, resultTwo{2};
    CHECK(resultOne == leetcode_so_03::findRepeatNumber(input));
    CHECK(resultTwo == leetcode_so_03::findRepeatNumber2(input));
    CHECK(resultTwo == leetcode_so_03::findRepeatNumber3(input));
}

TEST_CASE("test case 2 [test_so_03]", "[test_so_03]") {
    const vector<int32_t> input{2, 3, 1, 0, 2, 5, 3};
    static constexpr const auto resultOne{2}
    //, resultTwo{3}
    ;
    CHECK(resultOne == leetcode_so_03::findRepeatNumber(input));
    CHECK(resultOne == leetcode_so_03::findRepeatNumber2(input));
    CHECK(resultOne == leetcode_so_03::findRepeatNumber3(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP
