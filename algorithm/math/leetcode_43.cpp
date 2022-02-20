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
#include "leetcode_43_test.hpp"
#include <algorithm>

namespace leetcode_43 {


string leetcode_43::multiply(const string &num1, const string &num2) {
    static constexpr const char zeroC{'0'};
    static constexpr const char *const zero{"0"};
    if (num1 == zero || num2 == zero) {
        return zero;
    }
    const auto num1_size{num1.size()}, num2_size{num2.size()}, sum_size{num1_size + num2_size};
    vector<int32_t> sum(sum_size, 0);
    for (size_t i{num2_size}; i > 0; i--) {
        for (size_t j{num1_size}; j > 0; j--) {
            const auto plus{i + j - 1};
            const int32_t mul = static_cast<int32_t>(num2[i - 1] - zeroC) * static_cast<int32_t>(num1[j - 1] - zeroC);
            //cout << i << " " << j << " " << mul << endl;
            sum[plus - 1] += (mul + sum[plus]) / 10;
            sum[plus] = (mul + sum[plus]) % 10;
        }
    }
    string will_return;
    will_return.reserve(sum.size());
    for (size_t i = std::find_if(sum.begin(), sum.end(), [](int x) { return x != 0; }) - sum.begin();
         i < sum_size; i++) {
        will_return += static_cast<char>(sum[i] + static_cast<int>(zeroC));
    }
    return will_return;
}


}