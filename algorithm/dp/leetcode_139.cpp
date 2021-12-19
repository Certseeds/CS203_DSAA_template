
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