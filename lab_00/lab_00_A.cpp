// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

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

inline input_type read();

output_type cal(const input_type& data);

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

output_type cal(const input_type& data) {
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
