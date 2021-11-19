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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <vector>

namespace leetcode_56 {
using std::vector;

struct leetcode_56 {
    static vector<vector<int32_t>> merge(const vector<vector<int32_t>> &intervals);
};

using Catch::Matchers::Equals;

TEST_CASE("1 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1,  3},
                                         {2,  6},
                                         {8,  10},
                                         {15, 18}};
    const vector<vector<int32_t>> result{{{1, 6}, {8, 10}, {15, 18}}};
    CHECK_THAT(leetcode_56::merge(inputs), Equals(result));
}

TEST_CASE("2 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1, 4},
                                         {4, 5}};
    const vector<vector<int32_t>> result{{{1, 5}}};
    CHECK_THAT(leetcode_56::merge(inputs), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_HPP
