/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template

 * @Author: nanos
 * @Date: 2021-05-13 20:29:20
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2021  nanos

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_FFT_FFT_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_FFT_FFT_HPP


#include <cstdint>
#include <array>
#include <cassert>
#include <vector>
#include <complex>

namespace fft {
constexpr static int32_t base{10};
using std::vector;
using std::complex;

/**
 * 将10进制数字的每个数字拆开,装在数组中
 * 要求两个数组长度相等,且都为2的倍数,设为n
 * 返回一个长度为2n的数组,
 * 20210504被表达为vector<int32_t>{4,0,5,0,1,2,0,2};
 * */
vector<int32_t> multiply(const vector<int32_t> &one, const vector<int32_t> &sec);

inline void extend(vector<int32_t> &vec) {
    if (vec.empty()) {
        return;
    }
    size_t size{vec.size() - 1};
    int32_t powered{0};
    while (size != 0) {
        size /= 2;
        powered++;
    }
    size = vec.size();
    for (int32_t i{static_cast<int32_t>(size)}; i < (1 << powered); i++) {
        vec.emplace_back(0);
    }
}

inline vector<int32_t> num_to_vec(uint64_t uint64) {
    vector<int32_t> will_return{};
    while (uint64 != 0) {
        will_return.push_back(static_cast<int32_t>(uint64 % base));
        uint64 /= base;
    }
    extend(will_return);
    return will_return;
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_FFT_FFT_HPP
