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
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_401 {
using std::vector;

struct leetcode_401 {
    static vector<string> readBinaryWatch(int32_t num);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_401]", "[test_401]") {
    static constexpr const auto input{1};
    const vector<string> result{
            "0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"
    };
    CHECK_THAT(result, UnorderedEquals(leetcode_401::readBinaryWatch(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_HPP

