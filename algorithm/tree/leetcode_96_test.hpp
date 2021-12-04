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
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_HPP

#include <catch_main.hpp>
#include <unordered_map>

namespace leetcode_96 {

using std::unordered_map;
struct leetcode_96 {
    static int32_t numTrees(int32_t n);
};


TEST_CASE("test_case 1 [test_96]", "[test_96]") {
    static constexpr const auto input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_96::numTrees(input));
}

TEST_CASE("test_case 2 [test_96]", "[test_96]") {
    static constexpr const auto input{3};
    static constexpr const auto result{5};
    CHECK(result == leetcode_96::numTrees(input));
}
TEST_CASE("test_case 3 [test_96]", "[test_96]") {
    static constexpr const auto input{19};
    static constexpr const auto result{1767263190};
    CHECK(result == leetcode_96::numTrees(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_HPP
