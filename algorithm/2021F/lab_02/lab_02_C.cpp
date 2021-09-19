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
#include <cmath>
#include <tuple>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <iomanip>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_02_C{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::sort;
using std::array;
using std::tuple;
using std::string;
using std::vector;
static constexpr const char end{'\n'};
// 用wolframalpha 计算的 xe^(x/20)= b
static constexpr const double
        minV{0.9}, //b =1,   取得 0.9534461720025874945277780102832174149412593186778100427281924797
maxV{258}  //b =10^8 取得 257.40091767269424137944971165126822636856843117329338741172807922
;
static constexpr const auto pricesion = 0.0001f;
const auto functionProducer = [](int32_t b) {
    return [b](double x) {
        return x * std::exp(x / 20) - b; // 显然,递增函数
    };
};
using num_t = int32_t;
using input_type = vector<num_t>;
using output_type = vector<double>;

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
    num_t T{0};
    std::cin >> T;
    input_type inputs(T, -1);
    for (int32_t i{0}; i < T; i++) {
        std::cin >> inputs[i];
    }
    return inputs;
}

output_type::value_type cal_detail(num_t b) {
    double left{minV}, right{maxV}, middle{0.0f};
    const auto function = functionProducer(b);
    while (left < right) {
        middle = (left + right) / 2;
        const auto value = function(middle);
        if (-pricesion < value && value < pricesion) {
            return middle;
        } else if (value > 0) {
            right = middle;
        } else {
            left = middle;
        }
    }
    throw std::runtime_error("?");
}

output_type cal(const input_type &data) {
    const auto data_size = data.size();
    output_type outputs(data_size, -1.0f);
    for (size_t i{0}; i < data_size; i++) {
        outputs[i] = cal_detail(data[i]);
    }
    return outputs;
}

void output(const output_type &data) {
    cout << std::setprecision(10);
    for (auto &&value: data) {
        std::cout << value << end;
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
