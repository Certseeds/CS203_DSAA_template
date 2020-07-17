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
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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
const std::string end = "\n";


using input_data = tuple<int32_t, int32_t>;
using result_data = int32_t;

inline input_data read();

result_data cal(input_data &&data);

void output(const result_data &data);

#ifndef CS203_DSAA_TEST_MACRO
#define CS203_DSAA_TEST_MACRO

int main() {
    auto result_data = cal(read());
    output(result_data);
    return 0;
}

#endif // !CS203_DSAA_TEST_MACRO

inline input_data read() {
    int32_t a{0};
    int32_t b{0};
    std::cin >> a >> b;
    return std::make_tuple(a, b);
    }

result_data cal(input_data &&data) {
    int32_t a{0};
    int32_t b{0};
    tie(a, b) = data;
    int32_t c = a + b;
    return c;
    }

void output(const result_data &data)  {
    std::cout << data << end;
}