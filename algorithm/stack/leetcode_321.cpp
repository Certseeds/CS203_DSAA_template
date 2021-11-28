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


#include "leetcode_321_test.hpp"

namespace leetcode_321 {

int32_t compare(const vector<int32_t> &fst, size_t fst_size, const vector<int32_t> &snd, size_t snd_size) {
    if (fst.size() < snd.size()) {
        return -1;
    } else if (fst.size() > snd.size()) {
        return 1;
    } else {
        if (fst_size == fst.size()) {
            // 这个情况说明两者size相同并且全部相同,那就直接给1,-1都可以了
            return 1;
        } else if (fst[fst_size] > snd[snd_size]) {
            return 1;
        } else if (fst[fst_size] < snd[snd_size]) {
            return -1;
        } else {
            return compare(fst, fst_size + 1, snd, snd_size + 1);
        }
    }
}

vector<int32_t> leetcode_321::maxNumber(const vector<int32_t> &nums1, const vector<int32_t> &nums2, size_t k) {
    const auto nums1_size{nums1.size()}, nums2_size{nums2.size()};
    vector<int32_t> backup{};
    for (size_t x = std::max(0, static_cast<int32_t>(k) - static_cast<int32_t>(nums2_size)),
                 maxV{std::min(k, nums1_size)}; x <= maxV; x++) {
        const auto x_size{x},y_size{k - x};
        // 这里得注意, 先保证序列整体大小优先,
        // 再考虑保证整体单调栈特性
        const auto order = [](const vector<int32_t> &num, size_t needSize) {
            size_t remainSize = num.size() - needSize;
            stack<int32_t> sta;
            for (const auto ch: num) {
                while (remainSize > 0 && !sta.empty() && ch > sta.top()) {
                    sta.pop();
                    remainSize--;
                }
                sta.push(ch);
            }
            vector<int32_t> reserve{}, will_return{};
            while (!sta.empty()) {
                reserve.push_back(sta.top());
                sta.pop();
            }
            will_return.resize(reserve.size());
            std::copy(reserve.crbegin(), reserve.crend(), will_return.begin());
            return will_return;
        };
        const auto max1 = order(nums1, x_size);
        const auto max2 = order(nums2, y_size);
        if (x_size > max1.size() || y_size > max2.size()) {
            // 考虑了序列整体大小还是无法满足条件的情况
            continue;
        }
        const std::function<int(size_t, size_t)> comp = [&max1, &max2, &comp, x_size, y_size]
                (size_t fst, size_t snd) {
            if (fst == x_size) {
                return -1;
            } else if (snd == y_size) {
                return 1;
            } else if (max1[fst] > max2[snd]) {
                return 1;
            } else if (max1[fst] < max2[snd]) {
                return -1;
            } else {
                return comp(fst + 1, snd + 1);
            }
        };
        vector<int32_t> will_return{};
        for (size_t fst{0}, snd{0}, fst_size{x_size}, snd_size{y_size}; fst < fst_size || snd < snd_size;) {
            const auto choice = comp(fst, snd);
            if (choice == 1) {
                will_return.push_back(max1[fst]);
                fst++;
            } else if (choice == -1) {
                will_return.push_back(max2[snd]);
                snd++;
            }
        }
        if (compare(backup, 0, will_return, 0) < 0) {
            std::swap(backup, will_return);
        }
    }
    return backup;
}

}