/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
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

using std::cin;
using std::cout;
using std::string;
using std::tuple;
using std::vector;
const std::string end = "\n";

const vector<std::pair<int32_t, string>> spis{
        {2, "+---+"},
        {1, "/   /|"},
        {0, "+---+ |"},
        {0, "|   | +"},
        {0, "|   |/"},
        {0, "+---+"}};

using input_type = vector<vector<int32_t>>;
using output_type = vector<vector<char>>;

inline int main2();

inline input_type read();

void cal(input_type &hi);

void output(const output_type &map, int high, int wide);

void print(output_type &map, int a, int b);

#ifndef CS203_DSAA_TEST_MACRO
#define CS203_DSAA_TEST_MACRO

int main() {
    return main2();
}

#endif  // !CS203_DSAA_TEST_MACRO

inline int main2() {
    auto input_data = read();
    cal(input_data);
    // auto output_type = cal(read());
    // output(output_type);
    return 0;
}

inline input_type read() {
    int32_t m{0};
    int32_t n{0};
    std::cin >> m >> n;
    input_type mat(m + 1, vector<int32_t>(n + 1, -0x3f3f));
    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= n; ++i) {
            std::cin >> mat[k][i];
        }
    }
    return mat;
}

void print(output_type &map, int a, int b) {
    for (int i = 0; i < static_cast<int>(spis.size()); i++) {
        for (int j = 0; j < static_cast<int>(spis[i].second.size()); j++) {
            map[a - 1 + i][b + j + spis[i].first] = spis[i].second[j];
        }
    }
    return;
}

void cal(input_type &hi) {
    vector<vector<char>> out(302, vector<char>(301, '.'));
    int m = static_cast<int>(hi.size()) - 1;
    int n = static_cast<int>(hi.front().size()) - 1;
    int wide = 4 * n + 2 * m + 1;
    int h = -0x3f3f;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            h = std::max(h, hi[i][j] * 3 + 2 * (m - i + 1) + 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < hi[i][j]; k++) {
                int x = h - 3 * (k + 2) - 2 * (m - i) + 1;
                int y = 4 * j + 2 * (m - i - 1) - 1;
                print(out, x, y);
            }
        }
    }
    output(out, h, wide);
}

void output(const output_type &map, int high, int wide) {
    for (int i = 0; i < high; i++) {
        for (int j = 1; j <= wide; j++) {
            cout << map[i][j];
        }
        cout << end;
    }
}

static int faster_streams = [] {
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