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
#include "leetcode_so_05_test.hpp"

namespace leetcode_so_05 {
string leetcode_so_05::replaceSpace(const string &str) {
    size_t space{0};
    for (const auto ch: str) {
        if (ch == ' ') {
            space++;
        }
    }
    const auto str_size{str.size()};
    string will_return;
    will_return.resize((space << 1) + str_size);
    for (size_t r{str_size}, r_will{will_return.size() - 1}; r > 0; --r, --r_will) {
        if (str[r - 1] != ' ') {
            will_return[r_will] = str[r - 1];
        } else {
            will_return[r_will] = '0';
            --r_will;
            will_return[r_will] = '2';
            --r_will;
            will_return[r_will] = '%';
        }
    }
    return will_return;
}
}