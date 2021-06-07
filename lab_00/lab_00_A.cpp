/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 22:05:02
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
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
#include <tuple>
#include <vector>
#include <iostream>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_00_A{
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = tuple<num_t, num_t>;
using output_type = num_t;

inline int main2();

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t a{0}, b{0};
    std::cin >> a >> b;
    return std::make_tuple(a, b);
}

output_type cal(input_type data) {
    num_t a{0}, b{0};
    tie(a, b) = data;
    num_t c = a + b;
    return c;
}

void output(const output_type &data) {
    std::cout << data << end;
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