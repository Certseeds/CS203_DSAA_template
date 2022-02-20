/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_so_58_test.hpp"

namespace leetcode_so_58 {

string leetcode_so_58::reverseLeftWords(const string &s, int32_t n) {
    const auto s_size{s.size()};
    const auto mid{s_size - n};
    string will_reutrn(s_size, ' ');
    for (size_t i = n; i < s_size; ++i) {
        will_reutrn[i - n] = s[i];
    }
    for (int32_t i{0}; i < n; ++i) {
        will_reutrn[mid + i] = s[i];
    }
    return will_reutrn;
}

string leetcode_so_58::reverseWords(const string &s) {
    const auto s_size{s.size()};
    vector<string> strs;
    string str{};
    str.reserve(s_size);
    for (size_t left{0}; left < s_size; ++left, str.clear()) {
        for (; left < s_size && s[left] == ' '; ++left) {}
        for (; left < s_size && s[left] != ' '; ++left) { str += s[left]; }
        if (!str.empty()) {
            strs.push_back(str);
        }
    }
    if (strs.empty()) {
        return {};
    }
    string will_return{};
    will_return = strs.back();
    for (auto iter = strs.rbegin() + 1; iter != strs.rend(); ++iter) {
        //will_return =  will_return + *iter;
        will_return += ' ' + *iter;
    }
    return will_return;
}
}