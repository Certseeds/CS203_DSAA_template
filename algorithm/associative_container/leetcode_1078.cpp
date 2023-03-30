// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_1078_test.hpp"

namespace leetcode_1078 {

vector<string> leetcode_1078::findOcurrences(const string &text, const string &first, const string &second) {
    vector<unsigned long> vecs;
    vector<string> words{}, results{};
    const auto fstHash = std::hash<string>()(first);
    const auto sndHash = std::hash<string>()(second);
    string texts_{text};
    texts_.push_back(' ');
    const string &texts{texts_};
    for (size_t i{0}, length{1}; i < texts.size();) {
        if (texts[i + length] == ' ') {
            const auto substr{texts.substr(i, length)};
            vecs.push_back(std::hash<string>()(substr));
            words.push_back(substr);
            i += length + 1;
            length = 1;
        } else {
            length += 1;
        }
    }
    for (size_t i{1}; i + 1 < vecs.size(); ++i) {
        if (vecs[i - 1] == fstHash && vecs[i] == sndHash) {
            results.push_back(words[i + 1]);
        }
    }
    return results;
}

}
