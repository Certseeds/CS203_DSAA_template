/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
//@Tag DP
//@Tag 动态规划
//@Tag Trie
//@Tag 字典树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_139 {
using std::vector;

struct leetcode_139 final {
    static bool wordBreak(const string &s, const vector<string> &wordDict);
};

TEST_CASE("1 [test_139]", "[test_139]") {
    static constexpr const char *const input{"leetcode"};
    static constexpr const std::array<const char *const, 2> wordDict{"leet", "code"};
    CHECK(leetcode_139::wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}

TEST_CASE("2 [test_139]", "[test_139]") {
    static constexpr const char *const input{"applepenapple"};
    static constexpr const std::array<const char *const, 2> wordDict{"apple", "pen"};
    CHECK(leetcode_139::wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}

TEST_CASE("3 [test_139]", "[test_139]") {
    static constexpr const char *const input{"catsandog"};
    static constexpr const std::array<const char *const, 5> wordDict{"cats", "dog", "sand", "and", "cat"};
    CHECK_FALSE(leetcode_139::wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP
