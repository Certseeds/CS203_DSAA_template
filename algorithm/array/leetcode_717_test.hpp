/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_717 {
using std::vector;

struct leetcode_717 {
    static bool isOneBitCharacter(const vector<int32_t> &bits);
};

TEST_CASE("test case 1 [test_717]", "[test_717]") {
    const vector<int32_t> input{1, 0, 0};
    CHECK(leetcode_717::isOneBitCharacter(input));
}

TEST_CASE("test case 2 [test_717]", "[test_717]") {
    const vector<int32_t> input{1, 1, 1, 0};
    CHECK_FALSE(leetcode_717::isOneBitCharacter(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_HPP
