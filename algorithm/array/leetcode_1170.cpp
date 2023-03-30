// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1170_test.hpp"
#include <array>

namespace leetcode_1170 {
using std::array;

vector<int32_t> leetcode_1170::numSmallerByFrequency(const vector<string> &queries, const vector<string> &words) {
    static const auto minFunc = [](const string &word) {
        std::array<int32_t, 26> chars{0};
        for (const auto ch: word) {
            chars[ch - 'a'] += 1;
        }
        for (size_t i{0}; i < 26; ++i) {
            if (chars[i] != 0) {
                return chars[i];
            }
        }
        return 0;
    };
    vector<int32_t> nums(12, 0);
    for (const auto &word: words) {
        const auto minV = minFunc(word);
        nums[minV]++;
    }
    for (size_t i{1}; i < 12; ++i) {
        nums[i] = nums[i] + nums[i - 1];
    }
    vector<int32_t> will_return{};
    const auto words_size{words.size()};
    will_return.reserve(queries.size());
    for (const auto &query: queries) {
        const auto minV = minFunc(query);
        const auto value = nums[minV];
        will_return.push_back(words_size - value);
    }
    return will_return;
}

}
