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
//@Tag string
//@Tag 字符串
//@Tag HashMap
//@Tag 哈希表
//@Tag 滑动窗口
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_HPP

#include <catch_main.hpp>
#include <array>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

namespace leetcode_3 {
using std::endl;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;

struct leetcode_3 final{
    static int lengthOfLongestSubstring(const string &s);

    static int lengthOfLongestSubstring2(const string &s);

    static int lengthOfLongestSubstring3(const string &s);
};

void warpper(const string &s, int32_t length) {
    CHECK(leetcode_3::lengthOfLongestSubstring(s) == length);
    CHECK(leetcode_3::lengthOfLongestSubstring2(s) == length);
    CHECK(leetcode_3::lengthOfLongestSubstring3(s) == length);
}

TEST_CASE("1 [test 3]", "[test 3]") {
    string str{"abcabcbb"};
    warpper(str, 3);
}

TEST_CASE("2 [test 3]", "[test 3]") {
    string str{"bbbbb"};
    warpper(str, 1);
}

TEST_CASE("3 [test 3]", "[test 3]") {
    string str{"pwwkew"};
    warpper(str, 3);
}

TEST_CASE("4 [test 3]", "[test 3]") {
    string str{"abba"};
    cout << leetcode_3::lengthOfLongestSubstring(str) << endl;
    warpper(str, 2);
}

TEST_CASE("5 [test 3]", "[test 3]") {
    string str{" "};
    warpper(str, 1);
}

TEST_CASE("6 [test 3]", "[test 3]") {
    string str(3, '3');
    warpper(str, 1);
}

TEST_CASE("7 [test 3]", "[test 3]") {
    string str{"tmmzuxt"};
    warpper(str, 5);
}

TEST_CASE("8 [test 3]", "[test 3]") {
    string str{"1145141919810"};
    warpper(str, 4);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_HPP
