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
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_500 {
using std::array;
using std::vector;

struct leetcode_500 {
    static vector<string> findWords(const vector<string> &words);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 6> input{"Metal", "Gear", "Soild", "Venom", "Phantom",
                                                                  "Pain"};

    const vector<std::string> result{};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 2 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 4> input{"Hello", "Alaska", "Dad", "Peace"};

    const vector<std::string> result{"Alaska", "Dad"};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 3 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 3> input{"omk", "adsdf", "sfd"};

    const vector<std::string> result{"adsdf", "sfd"};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_HPP
