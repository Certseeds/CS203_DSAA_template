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
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_387 {

using std::string;

struct leetcode_387 {
    static int firstUniqChar(const string &s); // better for short str

    static int firstUniqChar2(const string &s); // better for long str
};

TEST_CASE("1 [test_387]", "[test_387]") {
    static constexpr const char *const input{"UD"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}

TEST_CASE("2 [test_387]", "[test_387]") {
    static constexpr const char *const input{"leetcode"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}

TEST_CASE("3 [test_387]", "[test_387]") {
    static constexpr const char *const input{"loveleetcode"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_HPP
