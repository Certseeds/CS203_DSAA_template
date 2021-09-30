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
 *@题目描述
 * 给出两个各有ν(希腊字母Nu),μ(希腊字母Mu)长的多项式Ν(大写希腊字母Nu),Μ(大写希腊字母Mu),请计算两者之和
 *@输入
 * 第一行输入两个int32_t,(0,10^6)
 * 之后ν行输入,分别是Ν的 ${系数},${指数}
 * 之后μ行输入,分别是Μ的 ${系数},${指数}
 * 所有系数指数都在(-10^9,10^9)
 * PS: 输入全为int32_t
 *@输出
 * 第一行int32_t, 输出项数
 * 之后分行输出 ${系数},${指数}
 * */
// DONE
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")

#include <map>
#include <iostream>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_04_A{
#endif

using std::cin;
using std::tie;
using std::map;
using std::cout;
static constexpr const char end{'\n'}, space{' '};
using num_t = int32_t;
using lab04map = std::map<num_t, num_t>;
const auto read = []() {
    // 好像有用,又好像没用的快读
    static int x, sign;
    static char c;
    x = 0;
    sign = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar();
    }
    for (; c >= '0' && c <= '9'; c = getchar()) {
        x = (x << 3) + (x << 1) + c - '0';
    }
    return x * sign;
};

int main() {
    num_t nu{0}, mu{0};
    num_t coeff{0}, expon{0};
    lab04map NU{};
    // nu = read();
    // mu = read();
    std::cin >> nu >> mu;
    for (num_t i{0}; i < nu; ++i) {
        //read(coeff),read(expon);
        std::cin >> coeff >> expon;
        NU[expon] = coeff;
    }
    for (num_t i{0}; i < mu; ++i) {
        //read(coeff),read(expon);
        std::cin >> coeff >> expon;
        NU[expon] += coeff;
    }
    std::cout << NU.size() << end;
    for (auto iter = NU.crbegin(); iter != NU.crend(); ++iter) {
        if (iter->first != 0) {
            std::cout << iter->second << space << iter->first << end;
        }
    }
    return 0;
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
