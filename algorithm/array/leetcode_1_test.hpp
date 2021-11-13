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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_HPP

#include <catch_main.hpp>
#include <unordered_map>

namespace leetcode_1 {
using std::unordered_map;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_1 {
    static vector<int> twoSum(const vector<int> &nums, int target);
};

TEST_CASE("basic tests [test_1]", "[test_1]") {
    const vector<int32_t> vec{2, 7, 11, 15};
    auto result = leetcode_1::twoSum(vec, 9);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int>({0, 1}));
    }
}

TEST_CASE("basic tests 2 [test_1]", "[test_1]") {
    const vector<int32_t> vec{3, 2, 4};
    auto result = leetcode_1::twoSum(vec, 6);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({1, 2}));
    }
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_HPP
