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
#include "leetcode_208_test.hpp"

namespace leetcode_208 {


void leetcode_208::trie::insert(const string& word) {
    uset.insert(word);
}

bool leetcode_208::trie::search(const string &word) {
    return uset.find(word) != std::end(uset);
}

bool leetcode_208::trie::startsWith(const string &prefix) {
    return
            std::any_of(std::cbegin(uset), std::cend(uset), [& prefix](const auto &item) {
                return prefix.size() <= item.size() && memcmp(item.c_str(), prefix.c_str(), prefix.size()) == 0;
            });
}


void leetcode_208::trie2::insert(const string& word) {
    std::array<Node *, 26> *array = &sons;
    for (size_t i{0}; i < word.size() - 1; i++) {
        const auto &ch = word[i] - 'a';
        if ((*array)[ch] == nullptr) {
            (*array)[ch] = new Node(ch, false);
        }
        array = &(*array)[ch]->sons;
    }
    {
        const auto &ch = word.back() - 'a';
        if ((*array)[ch] == nullptr) {
            (*array)[ch] = new Node(ch, false);
        }
        (*array)[ch]->isfinish = true;
    }
}

bool leetcode_208::trie2::search(const string &word) {
    const std::array<Node *, 26> *array = &sons;
    uint8_t isfinish{false};
    for (auto ch: word) {
        ch -= 'a';
        if ((*array)[ch] == nullptr) {
            return false;
        }
        isfinish = (*array)[ch]->isfinish;
        array = &(*array)[ch]->sons;
    }
    return isfinish;
}

bool leetcode_208::trie2::startsWith(const string &prefix) {
    const std::array<Node *, 26> *array = &sons;
    for (auto ch: prefix) {
        ch -= 'a';
        if ((*array)[ch] == nullptr) {
            return false;
        }
        array = &(*array)[ch]->sons;
    }
    return true;
}
}