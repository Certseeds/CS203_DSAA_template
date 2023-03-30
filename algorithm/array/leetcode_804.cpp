
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_804_test.hpp"
#include <unordered_set>

namespace leetcode_804 {
using std::unordered_set;

int32_t leetcode_804::uniqueMorseRepresentations(const vector<string> &words) {
    static constexpr const std::array<const char *const, 26> asks = {".-", "-...", "-.-.", "-..",
                                                                     ".", "..-.", "--.", "....",
                                                                     "..", ".---", "-.-",
                                                                     ".-..", "--", "-.", "---",
                                                                     ".--.", "--.-", ".-.", "...",
                                                                     "-", "..-", "...-", ".--",
                                                                     "-..-", "-.--", "--.."};
    unordered_set<string> uset;
    for (const auto &word: words) {
        string temp;
        temp.reserve(4 * word.size());
        for (const auto wchar: word) {
            temp += asks[wchar - 97];
        }
        if (uset.count(temp) == 0) {
            uset.insert(temp);
        }
    }
    return uset.size();
}
}
