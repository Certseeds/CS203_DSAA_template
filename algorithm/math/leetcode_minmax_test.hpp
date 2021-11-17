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
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MINMAX_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MINMAX_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <limits>

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
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_MINMAX_HPP
