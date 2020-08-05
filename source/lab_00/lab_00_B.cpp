/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseds
 * @Date: 2020-07-17 22:57:42
 * @LastEditors: nanoseds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020 nanoseds

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
// id: 1250
#include <list>
#include <deque>
#include <string>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::vector;
const std::string end = "\n";

using num_type = uint64_t;
using input_type = vector<num_type>;
using output_type = vector<num_type>;

inline input_type read();

output_type cal_warpper(const input_type &input);

num_type cal(num_type data);

num_type brute_force(num_type data);

void output(const output_type &data);

#ifndef CS203_DSAA_TEST_MACRO
#define CS203_DSAA_TEST_MACRO

int main() {
    input_type input_data = read();
    output_type output_data = cal_warpper(input_data);
    output(output_data);
    return 0;
}

#endif // !CS203_DSAA_TEST_MACRO

inline input_type read() {
    int32_t number{0};
    std::cin >> number;
    input_type will_return(number, 0);
    for (auto &item : will_return) {
        std::cin >> item;
    }
    return will_return;
}

output_type cal_warpper(const input_type &input) {
    output_type will_return(input.size(), 0);
    for (size_t i = 0; i < input.size(); ++i) {
        will_return[i] = cal(input[i]);
    }
    return will_return;
}

inline num_type cal(num_type data) {
    num_type will_return = data * (data + 1) * (data + 2) / 6;
    return will_return;
}

num_type brute_force(num_type data) {
    num_type will_return{0};
    for (num_type i = 1; i <= data; ++i) {
        will_return += i * (i + 1) / 2;
    }
    return will_return;
}

void output(const vector<num_type> &data) {
    for (const auto &num : data) {
        std::cout << num << end;
    }
}