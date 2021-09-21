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
//@Tag TODO
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_02_E{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = tuple<vector<num_t>, vector<num_t>, vector<std::pair<num_t, num_t>>>;
using output_type = vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t n{0}, T{0};
    std::cin >> n >> T;
    vector<num_t> A(n, -1), B(n, -1);
    for (int32_t i{0}; i < n; i++) {
        std::cin >> A[i];
    }
    for (int32_t i{0}; i < n; i++) {
        std::cin >> B[i];
    }
    num_t tempa, tempb;
    vector<std::pair<num_t, num_t>> pairs;
    for (int32_t i{0}; i < T; ++i) {
        std::cin >> tempa >> tempb;
        pairs.emplace_back(tempa, tempb);
    }
    return std::make_tuple(A, B, pairs);
}

output_type cal(const input_type &data) {
    vector<num_t> A, B;
    vector<std::pair<num_t, num_t>> pairs;
    tie(A, B, pairs) = data;
    // TODO
    return {};
}

void output(const output_type &data) {
    for (auto &&dat: data) {
        cout << dat << end;
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
