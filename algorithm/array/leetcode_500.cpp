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
#include "leetcode_500_test.hpp"

namespace leetcode_500 {

vector<string> leetcode_500::findWords(const vector<string> &words) {
    static constexpr const array<int, 58> chars = {
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
            2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3,
            0, 0, 0, 0, 0, 0,
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
            2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3};
    const auto words_size{words.size()};
    vector<string> willreturn;
    for (size_t i{0}; i < words_size; i++) {
        bool judge = true;
        for (size_t j{0}, size2{words[i].size() - 1}; j < size2; j++) {
            if (chars[words[i][j] - 65] != chars[words[i][j + 1] - 65]) {
                judge = false;
                break;
            }
        }
        if (judge) {
            willreturn.push_back(words[i]);
        }
    }
    return willreturn;
}

}
