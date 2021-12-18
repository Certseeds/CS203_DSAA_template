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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_60 {
struct leetcode_60 {
    static string getPermutation(int32_t n, int32_t k);

    static string getPermutation_rec_out(int32_t n, int32_t k);
};

TEST_CASE("1 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{3};
    static constexpr const char *const result{"213"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}

TEST_CASE("2 [test_60]", "[test_60]") {
    static constexpr const auto n{4}, k{9};
    static constexpr const char *const result{"2314"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}

TEST_CASE("3 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{1};
    static constexpr const char *const result{"123"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_HPP

