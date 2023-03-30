// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag Trie
//@Tag 字典树
//@Plan 动态规划入门 Day9
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>

namespace leetcode_139 {
using std::vector;
using std::string;

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
