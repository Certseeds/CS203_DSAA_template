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
#include "leetcode_118_119_test.hpp"

namespace leetcode_118 {

inline vector<int32_t> generate_help(vector<int32_t> vec, size_t order) {
    vector<int32_t> will_return{vec.cbegin(), vec.cend()};
    will_return.push_back(1);
    for (size_t i{1}; i < order; i++) {
        will_return[i] = vec[i - 1] + vec[i];
    }
    return will_return;
}

vector<vector<int32_t>> leetcode_118::generate(int32_t numRows) {
    vector<vector<int32_t>> will_return{};
    vector<int32_t> temp{};
    for (int32_t i{0}; i < numRows; i++) {
        temp = generate_help(temp, i);
        will_return.emplace_back(temp);
    }
    return will_return;
}

}

namespace leetcode_119 {


vector<int32_t> leetcode_119::getRow(int32_t rowIndex) {
    vector<int32_t> will_return(rowIndex + 1, 1);
    for (int32_t i{1}; i <= rowIndex; i++) {
        for (int j = i - 1; j > 0; j--) {
            will_return[j] += will_return[j - 1];
        }
    }
    return will_return;
}

/**
 * C^{N}_{M} = (m!) / ((n!) * (m-n)!)  <br>
 * C^{N+1}_{M} / C^{N}_{M} = (M-N)/(N+1) <br>
 * C^{N+1}_{M} = ((M-N)/(N+1)) * C^{N}_{M}
 * */
vector<int32_t> leetcode_119::getRowN(int32_t rowIndex) {
    vector<int32_t> will_return(rowIndex + 1, 1);
    for (int32_t i{1}; i <= rowIndex; i++) {
        const int64_t temp = static_cast<int64_t>(will_return[i - 1] ) * static_cast<int64_t>(rowIndex + 1 - i) / i;
        will_return[i] = static_cast<int32_t>(temp);
    }
    return will_return;
}
}