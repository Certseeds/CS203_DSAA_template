/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template

 * @Author: nanoseeds
 * @Date: 2020-07-21 21:44:25
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
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
// https://www.luogu.com.cn/problem/P1058
// luogu
// id: P1058
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_00_D{
#endif
using std::cin;
using std::cout;
using std::string;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};


using num_t = int32_t;
using input_type = vector<vector<num_t>>;
using output_type = vector<vector<char>>;

const vector<std::pair<num_t, string>> spis{
        {2, "+---+"},
        {1, "/   /|"},
        {0, "+---+ |"},
        {0, "|   | +"},
        {0, "|   |/"},
        {0, "+---+"}};

inline input_type read();

void cal(input_type &hi);

void output(const output_type &map, num_t high, num_t wide);

void print(output_type &map, num_t a, num_t b);

int main() {
    auto input_data = read();
    cal(input_data);
    return 0;
}

inline input_type read() {
    num_t m{0}, n{0};
    std::cin >> m >> n;
    input_type mat(m + 1, vector<num_t>(n + 1, -0x3f3f));
    for (num_t k = 1; k <= m; ++k) {
        for (num_t i = 1; i <= n; ++i) {
            std::cin >> mat[k][i];
        }
    }
    return mat;
}

void print(output_type &map, num_t a, num_t b) {
    for (auto i = 0; i < static_cast<num_t>(spis.size()); i++) {
        for (auto j = 0; j < static_cast<num_t>(spis[i].second.size()); j++) {
            map[a - 1 + i][b + j + spis[i].first] = spis[i].second[j];
        }
    }
}

void cal(input_type &hi) {
    vector<vector<char>> out(302, vector<char>(301, '.'));
    auto m = static_cast<num_t>(hi.size()) - 1;
    auto n = static_cast<num_t>(hi.front().size()) - 1;
    num_t wide = 4 * n + 2 * m + 1;
    num_t h = -0x3f3f;
    for (auto i = 1; i <= m; i++) {
        for (auto j = 1; j <= n; j++) {
            h = std::max(h, hi[i][j] * 3 + 2 * (m - i + 1) + 1);
        }
    }
    for (auto i = 1; i <= m; i++) {
        for (auto j = 1; j <= n; j++) {
            for (auto k = 0; k < hi[i][j]; k++) {
                num_t x = h - 3 * (k + 2) - 2 * (m - i) + 1;
                num_t y = 4 * j + 2 * (m - i - 1) - 1;
                print(out, x, y);
            }
        }
    }
    output(out, h, wide);
}

void output(const output_type &map, num_t high, num_t wide) {
    for (auto i = 0; i < high; i++) {
        for (num_t j = 1; j <= wide; j++) {
            cout << map[i][j];
        }
        cout << end;
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