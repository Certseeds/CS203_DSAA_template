// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1002_test.hpp"

namespace leetcode_1002 {
static constexpr const size_t chars{26};

vector<string> leetcode_1002::commonChars(const vector<string> &words) {
    std::array<uint8_t, chars> arr{0};
    std::fill(arr.begin(), arr.end(), 100);
    for (const auto &word: words) {
        std::array<uint8_t, chars> nums{0};
        for (const auto &ch: word) {
            ++nums[ch - 'a'];
        }
        for (size_t i{0}; i < chars; ++i) {
            arr[i] = std::min(nums[i], arr[i]);
        }
    }
    vector<string> will_return{};
    for (char i{'a'}; i <= 'z'; ++i) {
        const auto ch = arr[i - 'a'];
        for (size_t j{1}; j <= ch; j++) {
            will_return.push_back(std::string{i});
        }
    }
    return will_return;
}

}
