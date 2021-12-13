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
int64_t zero_one_package::Package::solve() const {
    const auto thing_size = things.size();
    vector<vector<int64_t>> dp;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    if constexpr (T == allow_unfull::UN_ALLOW) {
        dp = vector<vector<int64_t>>(thing_size + 1, vector<int64_t>(full + 1, 0));
    } else {
        dp = vector<vector<int64_t>>(thing_size + 1, vector<int64_t>(full + 1, -0x3f3f3f3f));
    }
    for (int64_t i{1}; i <= full; i++) {
        dp[0][i] = -0x3f3f3f3f; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{0}; i <= thing_size; i++) {
        dp[i][0] = 0; // 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= thing_size; i++) {
        for (int64_t j{1}; j <= full; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            const auto cost{things[i - 1].cost}, money{things[i - 1].money};
            if (j >= cost) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - cost] + money);
            }
        }
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return dp.back().back();
    } else {
        return *std::max_element(std::cbegin(dp.back()), std::cend(dp.back()));
    }
}

template<allow_unfull T>
int64_t zero_one_package::Package::solveSaveSpace() const {
    const auto thing_size = things.size();
    vector<int64_t> lastLine, nowLine;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    if constexpr (T == allow_unfull::UN_ALLOW) {
        lastLine = vector<int64_t>(full + 1, 0);
        nowLine = vector<int64_t>(full + 1, 0);
    } else {
        lastLine = vector<int64_t>(full + 1, -0x3f3f3f3f);
        nowLine = vector<int64_t>(full + 1, -0x3f3f3f3f);
    }
    for (int64_t i{1}; i <= full; i++) {
        lastLine[i] = -0x3f3f3f3f; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{0}; i <= thing_size; i++) {
        lastLine[0] = 0;
        nowLine[0] = 0;// 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= thing_size; i++) {
        for (int64_t j{1}; j <= full; j++) {
            nowLine[j] = std::max(lastLine[j], nowLine[j]);
            const auto cost{things[i - 1].cost}, money{things[i - 1].money};
            if (j >= cost) {
                nowLine[j] = std::max(nowLine[j], lastLine[j - cost] + money);
            }
        }
        std::swap(lastLine, nowLine);
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return lastLine.back();
    } else {
        return *std::max_element(std::cbegin(lastLine), std::cend(lastLine));
    }
}

template<allow_unfull T>
int64_t zero_one_package::Package::solveOneLine() const {
    const auto thing_size = things.size();
    const auto ful = this->full;
    vector<int64_t> line;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    line = vector<int64_t>(ful + 1, -0x3f3f3f3f);
    line[0] = 0;
    const auto zeroOnePack = [&line, ful](const something &thing) {
        for (int64_t j{ful}; j >= 1; j--) {
            const auto cost{thing.cost}, money{thing.money};
            if (j >= cost) {
                line[j] = std::max(line[j], line[j - cost] + money);
            }
        }
    };
    for (size_t i{1}; i <= thing_size; i++) {
        zeroOnePack(things[i - 1]);
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return line.back();
    } else {
        return *std::max_element(std::cbegin(line), std::cend(line));
    }
}
}
