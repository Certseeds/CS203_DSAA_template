/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021 nanoseeds

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
//@Tag Done

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_02_D{
#endif
// 10^9 * 2 < 2^31 -1
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using std::unordered_map;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = vector<num_t>;
using output_type = size_t;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    size_t n{0};
    std::cin >> n;
    vector<num_t> nums(n, -1);
    for (size_t i{0}; i < n; i++) {
        std::cin >> nums[i];
    }
    return nums;
}

output_type cal(const input_type &data) {
    const auto judge = [](const int32_t n) {
        return (n & (n - 1)) == 0;
    };
    const auto make_unique = [](size_t left, size_t right) {
        return (left << 32) + right;
    };
    const auto arr = [] {
        vector<int32_t> vec(32, 1);
        for (size_t i{1}; i < 32; ++i) {
            vec[i] = 2 * vec[i - 1];
        }
        return vec;
    }();
    const auto data_size = data.size();
    unordered_map<num_t, size_t> sizes{};
    unordered_map<uint64_t, uint64_t> uset{};
    for (size_t i{0}; i < data_size; i++) {
        if (sizes.find(data[i]) == sizes.end()) {
            sizes[data[i]] = (i << 32) + 1;
        } else {
            sizes[data[i]]++;
        }
    }
    size_t same_count{0};
    for (const auto pair: sizes) {
        const num_t key = pair.first;
        const size_t value = pair.second;
        const size_t count_num = ((value << 32) >> 32);
        //std::cout << val << " " << value << " " << count_num << end;
        if (judge(key)) {
            same_count += (count_num * (count_num - 1)) / 2;
        }
    }
    for (size_t i{0}; i < data_size; i++) {
        for (size_t j{31}; j >= 1; j--) {
            if (sizes.find(arr[j] - data[i]) != sizes.cend()) {
                const auto rhs = sizes[arr[j] - data[i]];
                const auto rhs_loca = rhs >> 32;
                if (i < rhs_loca) {
                    const auto count = make_unique(i, rhs);
                    const auto count_size = (rhs << 32) >> 32;
                    uset[count] += count_size;
                }
            }
        }
    }
    return std::accumulate(uset.begin(), uset.end(), same_count,
                           [](uint64_t lhs, const std::pair<uint64_t, uint64_t> &rhs) {
                               return lhs + rhs.second;
                           });
}

void output(const output_type &data) {
    cout << data << end;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
