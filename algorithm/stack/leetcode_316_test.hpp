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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_HPP

#include <catch_main.hpp>
#include <stack>
#include <string>
#include <unordered_set>

namespace leetcode_316 {
using std::stack;
using std::string;
using std::string_view;
using std::unordered_set;

struct leetcode_316 {
    static string removeDuplicateLetters(string_view s);
};
TEST_CASE("2 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cbacdcbc"};
    static constexpr const char *const output{"acdb"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("1 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bcabc"};
    static constexpr const char *const output{"abc"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("3 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cdadabcc"};
    static constexpr const char *const output{"adbc"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("4 [test_316]", "[test_316]") {
    static constexpr const char *const input{"abcd"};
    static constexpr const char *const output{"abcd"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("5 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bddbccd"};
    static constexpr const char *const output{"bcd"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}
TEST_CASE("6 [test_316]", "[test_316]") {
    static constexpr const char *const input{"thesqtitxyetpxloeevdeqifkz"};
    leetcode_316::removeDuplicateLetters(input);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_HPP
