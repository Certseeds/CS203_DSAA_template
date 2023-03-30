// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

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
