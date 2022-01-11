/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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

#include "divide_bar.hpp"
#include "divide_bar_test.hpp"

namespace dp_divide_bar {
namespace iter {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length) {
    const auto divide_profits_size{divide_profits.size()};
    const auto minIter{std::min(divide_profits_size, length)};
    vector<int64_t> profits_table(length + 1, -0x3f3f3f);
    profits_table[0] = 0;
    for (size_t i{0}; i < minIter; i++) {
        profits_table[i + 1] = divide_profits[i];
    }
    for (size_t i{2}; i <= length; i++) {
        for (size_t j{1}; j < (i / 2 + 1); j++) {
            profits_table[i] = std::max(profits_table[i], profits_table[j] + profits_table[i - j]);
        }
    }
    return profits_table.back();
}
}
namespace rec {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length) {

    return 0;
}
}
}

