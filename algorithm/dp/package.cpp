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

#include "package.hpp"
#include "package_test.hpp"

namespace zero_one_package {
template<allow_unfull T>
size_t zero_one_package::Package::solve() {
    const auto thing_size = things.size();
    vector<vector<size_t>> dp;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    if constexpr (T == allow_unfull::UN_ALLOW) {
        dp = vector<vector<size_t>>(thing_size + 1, vector<size_t>(full + 1, 0));
    } else {
        dp = vector<vector<size_t>>(thing_size + 1, vector<size_t>(full + 1, -0x3f3f3f3f));
        dp[0][0] = 0;
    }
    for (size_t i{1}; i <= full; i++) {
        dp[0][i] = -0x3f3f3f3f; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{1}; i <= thing_size; i++) {
        dp[i][0] = 0; // 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= thing_size; i++) {
        for (size_t j{1}; j <= full; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            const auto cost{things[i].cost}, money{things[i].money};
            if (j >= cost) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - cost] + money);
            }
        }
    }
    return dp.back().back();
}

}
