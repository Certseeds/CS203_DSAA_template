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
/*
 * @题目描述
 * 匹配括号,输出是否匹配
 * */
//@Tag DONE

#ifndef CS203_DSAA_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#endif

#include <array>
#include <tuple>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <iostream>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_05_C{
#endif

using std::cin;
using std::cout;
using std::stack;
using std::tuple;
using std::string;
using std::vector;

static constexpr const char end{'\n'}, space{' '};
struct OUTPUT final {
    static constexpr const char *const YES{"YES"};
    static constexpr const char *const NO{"NO"};
};
using num_t = int32_t;
using input_type = vector<std::string>;
using output_type = vector<uint8_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int32_t main() {
    const auto input_data{read()};
    const auto output_data{cal(input_data)};
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t tau{0}, uesless{-1};
    std::cin >> tau;
    vector<string> strs(tau);
    for (num_t i{0}; i < tau; ++i) {
        std::cin >> uesless >> strs[i];
    }
    return strs;
}

namespace MAP {
static const auto umap = [] {
    static std::array<uint8_t, std::numeric_limits<uint8_t>::max() + 1> arr{0};
    arr['('] = ')';
    arr['['] = ']';
    arr['{'] = '}';
    return arr;
}();
}

output_type cal(const input_type &data) {
    vector<string> strs{data};
    vector<uint8_t> will_return{};
    will_return.reserve(strs.size());
    for (const auto &str: strs) {
        std::stack<uint8_t> stk{{'?'}};
        for (const auto i: str) {
            if (MAP::umap.at(stk.top()) == i) {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        stk.pop();
        will_return.emplace_back(stk.empty());
    }
    return will_return;
}

void output(const output_type &data) {
    for (auto &&ele: data) {
        if (ele == true) {
            std::cout << OUTPUT::YES;
        } else {
            std::cout << OUTPUT::NO;
        }
        std::cout << end;
    }
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
