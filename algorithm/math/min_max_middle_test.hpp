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
//@Tag list
//@Tag 数学
//@Description 最大值
//@Description 最小值

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <limits>
#include <random>

namespace leetcode_minmax {
struct minmax final {
    const int32_t min{}, max{};

    bool operator==(const minmax &inAx) const {
        return this->min == inAx.min && this->max == inAx.max;
    }
};

struct leetcode_minmax {
    static int32_t minV(const vector<int32_t> &values);

    static int32_t maxV(const vector<int32_t> &values);

    static minmax minMaxV(const vector<int32_t> &values);

    static int32_t random_partition(vector<int32_t> &values, int32_t begin, int32_t end);

    static int32_t partition(vector<int32_t> &values, int32_t begin, int32_t end);

    static int32_t middleV(vector<int32_t> &values, int32_t begin, int32_t end, int32_t ith);
};

TEST_CASE("basic test [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1, 2, 0};
    const static constexpr auto min{0}, max{2};
    CHECK(min == leetcode_minmax::minV(input));
    CHECK(max == leetcode_minmax::maxV(input));
    CHECK(minmax{min, max} == leetcode_minmax::minMaxV(input));
}

TEST_CASE("basic test 2 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{3, 4, -1, 1};
    const static constexpr auto min{-1}, max{4};
    CHECK(min == leetcode_minmax::minV(input));
    CHECK(max == leetcode_minmax::maxV(input));
    CHECK(minmax{min, max} == leetcode_minmax::minMaxV(input));
}

TEST_CASE("basic test 3 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{7, 8, 9, 11, 12};
    const static constexpr auto min{7}, max{12};
    CHECK(min == leetcode_minmax::minV(input));
    CHECK(max == leetcode_minmax::maxV(input));
    CHECK(minmax{min, max} == leetcode_minmax::minMaxV(input));
}

TEST_CASE("basic test 4 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1};
    const static constexpr auto min{1}, max{1};
    CHECK(min == leetcode_minmax::minV(input));
    CHECK(max == leetcode_minmax::maxV(input));
    CHECK(minmax{min, max} == leetcode_minmax::minMaxV(input));
}

TEST_CASE("basic test 5 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1, 2, 2, 1, 1, 3, 3, 4, 5};
    const static constexpr auto min{1}, max{5};
    CHECK(min == leetcode_minmax::minV(input));
    CHECK(max == leetcode_minmax::maxV(input));
    CHECK(minmax{min, max} == leetcode_minmax::minMaxV(input));
}

TEST_CASE("basic test 6 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 1, 8, 1, 0, 4, 1, 9, 1, 9, 4, 1, 5};
    CHECK(9 == leetcode_minmax::partition(input, 0, 12));
}

TEST_CASE("basic test 7 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int32_t i{1}; i < 10; i++) {
        CHECK(i == leetcode_minmax::middleV(input, 0, 9, i));
    }
    for (int32_t i{1}; i < 9; i++) {
        CHECK(i == leetcode_minmax::middleV(input, 0, 8, i));
    }
}

TEST_CASE("basic test 8 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 4, 5, 7, 8, 9, 6, 2, 3, 10};
    for (int32_t i{1}; i < 10; i++) {
        CHECK(i == leetcode_minmax::middleV(input, 0, 9, i));
    }
    for (int32_t i{1}; i < 9; i++) {
        CHECK(i == leetcode_minmax::middleV(input, 0, 8, i));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP
