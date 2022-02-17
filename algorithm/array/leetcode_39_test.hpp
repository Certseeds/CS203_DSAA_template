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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_39 {
using std::vector;

struct leetcode_39 {
    static vector<vector<int32_t>> combinationSum(const vector<int32_t> &candidates, int target);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic test [test_39]", "[test_39]") {
    const vector<int32_t> candidates{2, 3, 6, 7};
    const static constexpr auto target{7};
    const vector<vector<int32_t>> results{{7},
                                          {2, 2, 3}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 2[test_39]", "[test_39]") {
    const vector<int32_t> candidates{2, 3, 5};
    const static constexpr auto target{8};
    const vector<vector<int32_t>> results{{2, 3, 3},
                                          {2, 2, 2, 2},
                                          {3, 5}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 3[test_39]", "[test_39]") {
    const vector<int32_t> candidates{2};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 4[test_39]", "[test_39]") {
    const vector<int32_t> candidates{1};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{{1}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 5[test_39]", "[test_39]") {
    const vector<int32_t> candidates{1};
    const static constexpr auto target{2};
    const vector<vector<int32_t>> results{{1, 1}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_HPP
