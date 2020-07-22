/**
 * @Github: https://github.com/${GITHUB_USER}/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:31:25 
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020  nanoseeds

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
#include <vector>
#include <iostream>
#include "catch_main.hpp"
#include "sort_wrapper.hpp"

using std::vector;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
static int srand_get = []() {
    srand(time(0));
    return 0;
}();

TEST_CASE("empty", "[sort]") {
    vector<int> nums{};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("size 1", "[sort]") {
    vector<int> nums{rand() % 0x3f3f};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test", "[sort]") {
    vector<int> nums{3, 2, 1, 5, 6, 4};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test 2", "[sort]") {
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test 3", "[sort]") {
    vector<int> nums{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("random test", "[sort]") {
    vector<int> nums{};
    nums.reserve(1145);
    for (int i = 0; i < 1145; ++i) {
        nums.push_back(rand() % 114514);
    }
    vector<int> nums_result(nums);

    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}