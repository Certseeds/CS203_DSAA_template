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
#include "leetcode_279_test.hpp"

namespace leetcode_279 {

vector<int32_t> getSquList(int32_t x) {
    vector<int32_t> will_return{};
    for (int32_t i{1}; i * i <= x; i++) {
        will_return.push_back(i * i);
    }
    return will_return;
}

static constexpr const auto maxNum{10000};

int32_t leetcode_279::numSquares(int32_t n) {
    const auto squList{getSquList(maxNum)};
    const auto squ_list_size{squList.size()};
    vector<int32_t> dp(n + 1);
    std::iota(std::begin(dp), std::end(dp), 0); // 只有1组成
    for (size_t j{0}; j < squ_list_size && squList[j] <= n; j++) {
        dp[squList[j]] = 1; // 本身就是平方数
    }
    for (int32_t i{1}; i <= n; i++) {
        for (size_t j{0}; j < squ_list_size && squList[j] <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - squList[j]] + 1); // 寻找子问题
        }
    }
    return dp.back();
}

}