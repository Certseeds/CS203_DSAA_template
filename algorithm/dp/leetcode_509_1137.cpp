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
#include "leetcode_509_1137_test.hpp"
#include <array>

namespace leetcode_509 {
using std::array;
static constexpr const size_t max{31};

constexpr auto func() {
    std::array<int32_t, max> fib{0};
    fib[1] = 1;
    for (size_t i{2}; i < max; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

int32_t leetcode_509::fib(int32_t n) {
    static constexpr const std::array<int32_t, func().size()> arr = func();
    return arr[n];
}

}
namespace leetcode_1137 {
using std::array;
static constexpr const size_t maxV{38};

constexpr auto func() {
    std::array<int32_t, maxV> fib{0};
    fib[1] = 1;
    fib[2] = 1;
    for (size_t i{3}; i < maxV; i++) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
    }
    return fib;
}

int32_t leetcode_1137::tribonacci(int32_t n) {
    static constexpr const std::array<int32_t, func().size()> arr = func();
    return arr[n];
}

}
