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
#include "leetcode_minmax_test.hpp"

namespace leetcode_minmax {

int32_t leetcode_minmax::minV(const vector<int32_t> &values) {
    int32_t minV{std::numeric_limits<int32_t>::max()};
    for (const auto &value: values) {
        minV = std::min(minV, value);
    }
    return minV;
}

int32_t leetcode_minmax::maxV(const vector<int32_t> &values) {
    int32_t maxV{std::numeric_limits<int32_t>::min()};
    for (const auto &value: values) {
        maxV = std::max(maxV, value);
    }
    return maxV;
}

minmax leetcode_minmax::minMaxV(const vector<int32_t> &values) {
    int32_t minV{std::numeric_limits<int32_t>::max()}, maxV{std::numeric_limits<int32_t>::min()};
    const auto values_size{values.size()}, values_size_{(values_size / 2) * 2};
    if (values_size != values_size_) {
        minV = values.back();
        maxV = values.back();
    }
    for (size_t i{0}; i < values_size_; i += 2) {
        if (values[i] < values[i + 1]) {
            minV = std::min(minV, values[i]);
            maxV = std::max(maxV, values[i + 1]);
        } else {
            minV = std::min(minV, values[i + 1]);
            maxV = std::max(maxV, values[i]);
        }
    }
    return {minV, maxV};
}
}