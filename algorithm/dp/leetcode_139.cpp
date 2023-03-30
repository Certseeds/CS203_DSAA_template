
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_139_test.hpp"
#include <tree/trie.hpp>

namespace leetcode_139 {
using trieIter::trie;

bool leetcode_139::wordBreak(const string &s, const vector<string> &wordDict) {
    const auto s_size{s.size()};
    size_t wordMin{0x3f3f3f3f};
    trie Trie{};
    for (const auto &word: wordDict) {
        Trie.insert(word.cbegin(), word.cend());
        wordMin = std::min(wordMin, word.size());
    }
    if (s_size < wordMin) {
        return false; // can not even spell into smallest word
    }
    vector<uint8_t> dp(s_size + 1, false);
    //dp[i] => the ith word match or not
    dp[0] = true;
    for (size_t i{1}; i <= s_size; i++) {
        for (size_t j{0}; j < i; j++) {
            dp[i] = dp[i] ||
                    (dp[j] && Trie.search(s.cbegin() + j, s.cbegin() + i));
        }
    }
    return dp.back();
}

}
