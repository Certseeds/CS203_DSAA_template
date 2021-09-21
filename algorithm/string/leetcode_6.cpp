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
#include "leetcode_6_test.hpp"

namespace leetcode_6 {
string leetcode_6::convert(const string &s, int numRows) {
    const auto s_size{s.size()}, numRows_size{static_cast<size_t>(numRows)};
    if (s_size <= numRows_size || numRows_size == 1) {
        return s;
    }
    vector<uint8_t> vec(s_size);
    const size_t batch{numRows_size * 2 - 2},
            block_number{s_size / batch},
            batch_size{batch * block_number},
            left_num{s_size - batch_size};
    size_t count{0uLL};
    for (size_t i{0}; i < s_size; i += batch, count++) {
        vec[count] = s[i];
    }
    for (size_t i{1}; i < numRows_size - 1; i++) {
        for (size_t j{0}; j < batch_size; j += batch, count += 2) {
            vec[count] = s[j + i];
            vec[count + 1] = s[j + batch - i];
        }
        if (left_num > i) {
            vec[count] = s[batch_size + i];
            count++;
            if (left_num > batch - i) {
                vec[count] = s[batch_size + batch - i];
                count++;
            }
        }
    }
    for (size_t i{0}; i < batch_size; i += batch, count++) {
        vec[count] = s[i + (numRows_size - 1)];
    }
    if (left_num >= numRows_size) {
        vec[count] = s[batch_size + numRows_size - 1];
    }
    return {vec.cbegin(), vec.cend()};
}

}