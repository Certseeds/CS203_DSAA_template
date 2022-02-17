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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_283 {
using std::vector;

struct leetcode_283 {
    static void moveZeroes(vector<int32_t> &nums);

    static void moveZeroes2(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_283]", "[test_283]") {
    vector<int32_t> input{0, 1, 0, 3, 12};
    const vector<int32_t> result{1, 3, 12, 0, 0};
    WHEN("one node") {
        leetcode_283::moveZeroes(input);
        THEN("the values") {
            CHECK_THAT(result, Equals(input));
        }
    }WHEN("one node") {
        leetcode_283::moveZeroes2(input);
        THEN("the values") {
            CHECK_THAT(result, Equals(input));
        }
    }

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP

