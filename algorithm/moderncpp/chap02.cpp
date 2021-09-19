/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template

 * @Author: nanos
 * @Date: 2021-06-13 19:38:35
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
// answer for Q1
// https://github.com/changkun/modern-cpp-tutorial/blob/master/book/zh-cn/02-usability.md
#include <map>
#include <iostream>

namespace moderncpp::chap02 {
using std::map;
using std::cout, std::endl;

int32_t main();

template<typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F foo) {
    for (auto[key, value]: m) { m[key] = foo(key); }
}

template<typename Key, typename Value, typename F>
void update2(std::map<Key, Value> &m, F foo) {
    for (auto&[key, value]: m) { value = foo(key); }
}

void main1() {
    std::map<std::string, long long int> m{
            {"a", 1},
            {"b", 2},
            {"c", 3}
    };
    update(m, [](const std::string &key) {
        return std::hash<std::string>{}(key);
    });
    for (auto&&[key, value]: m) {
        std::cout << key << ":" << value << std::endl;
    }
}

template<typename ... T>
auto sum(T ...t) {
    return (t + ...) / sizeof...(t);
}

void main2() {
    std::cout << sum(1.0f) << std::endl;
    std::cout << sum(1.0f, 2) << std::endl;
    std::cout << sum(1.0f, 2.0f, 3) << std::endl;
    std::cout << sum(1.0f, 2.0f, 3.0f, 4) << std::endl;
    std::cout << sum(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 6.0f, 7.0f, 7.0f, 7) << std::endl;
}

int main() {
    main1();
    main2();
    return 0;
}
}

int32_t main() {
    return moderncpp::chap02::main();
}