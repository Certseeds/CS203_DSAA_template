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
//@Tag Trie
//@Tag 字典树
//@Tag 模拟
//@Tag 偷鸡
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_212_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_212_TEST_HPP

#include <catch_main.hpp>

#include <array>
#include <stack>
#include <string>
#include <unordered_set>

namespace leetcode_212 {
using std::array;
using std::stack;
using std::string;
using std::unordered_set;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_212 {
    static vector<string> findWords(vector<vector<char>> &board, const vector<string> &words);
};

TEST_CASE("test basic 1[test_212]", "[test_212]") {
    vector<vector<char>> board{{'o', 'a', 'b', 'n'},
                               {'o', 't', 'a', 'e'},
                               {'a', 'h', 'k', 'r'},
                               {'a', 'f', 'l', 'v'}};
    const vector<string> words{"oa", "oaa"};
    const vector<string> &results{words};
    CHECK_THAT(leetcode_212::findWords(board, words), UnorderedEquals<string>(results));
}

TEST_CASE("test basic 2[test_212]", "[test_212]") {
    vector<vector<char>> board{{'o', 'a', 'a', 'n'},
                               {'e', 't', 'a', 'e'},
                               {'i', 'h', 'k', 'r'},
                               {'i', 'f', 'l', 'v'}};
    const vector<string> words{"oath", "pea", "eat", "rain"};
    const vector<string> results{"eat", "oath"};
    CHECK_THAT(leetcode_212::findWords(board, words), UnorderedEquals<string>(results));
}

TEST_CASE("test basic 3[test_212]", "[test_212]") {
    vector<vector<char>> board{
            {'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a'}};
    const vector<string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
    const vector<string> results{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
    CHECK_THAT(leetcode_212::findWords(board, words), UnorderedEquals<string>(results));
}

TEST_CASE("test basic 4[test_212]", "[test_212]") {
    vector<vector<char>> board{
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}};
    const vector<string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                               "aaaaaaaaaa"};
    const vector<string> results{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                                 "aaaaaaaaaa"};
    CHECK_THAT(leetcode_212::findWords(board, words), UnorderedEquals<string>(results));
}

TEST_CASE("test basic 5[test_212]", "[test_212]") {
    vector<vector<char>> board{
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}};
    const vector<string> words{"lllllll", "fffffff", "ssss", "s", "rr", "xxxx", "ttt", "eee", "ppppppp", "iiiiiiiii",
                               "xxxxxxxxxx", "pppppp", "xxxxxx", "yy", "jj", "ccc", "zzz", "ffffffff", "r", "mmmmmmmmm",
                               "tttttttt", "mm", "ttttt", "qqqqqqqqqq", "z", "aaaaaaaa", "nnnnnnnnn", "v", "g",
                               "ddddddd", "eeeeeeeee", "aaaaaaa", "ee", "n", "kkkkkkkkk", "ff", "qq", "vvvvv", "kkkk",
                               "e", "nnn", "ooo", "kkkkk", "o", "ooooooo", "jjj", "lll", "ssssssss", "mmmm", "qqqqq",
                               "gggggg", "rrrrrrrrrr", "iiii", "bbbbbbbbb", "aaaaaa", "hhhh", "qqq", "zzzzzzzzz",
                               "xxxxxxxxx", "ww", "iiiiiii", "pp", "vvvvvvvvvv", "eeeee", "nnnnnnn", "nnnnnn", "nn",
                               "nnnnnnnn", "wwwwwwww", "vvvvvvvv", "fffffffff", "aaa", "p", "ddd", "ppppppppp", "fffff",
                               "aaaaaaaaa", "oooooooo", "jjjj", "xxx", "zz", "hhhhh", "uuuuu", "f", "ddddddddd",
                               "zzzzzz", "cccccc", "kkkkkk", "bbbbbbbb", "hhhhhhhhhh", "uuuuuuu", "cccccccccc", "jjjjj",
                               "gg", "ppp", "ccccccccc", "rrrrrr", "c", "cccccccc", "yyyyy", "uuuu", "jjjjjjjj", "bb",
                               "hhh", "l", "u", "yyyyyy", "vvv", "mmm", "ffffff", "eeeeeee", "qqqqqqq", "zzzzzzzzzz",
                               "ggg", "zzzzzzz", "dddddddddd", "jjjjjjj", "bbbbb", "ttttttt", "dddddddd", "wwwwwww",
                               "vvvvvv", "iii", "ttttttttt", "ggggggg", "xx", "oooooo", "cc", "rrrr", "qqqq", "sssssss",
                               "oooo", "lllllllll", "ii", "tttttttttt", "uuuuuu", "kkkkkkkk", "wwwwwwwwww",
                               "pppppppppp", "uuuuuuuu", "yyyyyyy", "cccc", "ggggg", "ddddd", "llllllllll", "tttt",
                               "pppppppp", "rrrrrrr", "nnnn", "x", "yyy", "iiiiiiiiii", "iiiiii", "llll", "nnnnnnnnnn",
                               "aaaaaaaaaa", "eeeeeeeeee", "m", "uuu", "rrrrrrrr", "h", "b", "vvvvvvv", "ll", "vv",
                               "mmmmmmm", "zzzzz", "uu", "ccccccc", "xxxxxxx", "ss", "eeeeeeee", "llllllll", "eeee",
                               "y", "ppppp", "qqqqqq", "mmmmmm", "gggg", "yyyyyyyyy", "jjjjjj", "rrrrr", "a", "bbbb",
                               "ssssss", "sss", "ooooo", "ffffffffff", "kkk", "xxxxxxxx", "wwwwwwwww", "w", "iiiiiiii",
                               "ffff", "dddddd", "bbbbbb", "uuuuuuuuu", "kkkkkkk", "gggggggggg", "qqqqqqqq",
                               "vvvvvvvvv", "bbbbbbbbbb", "nnnnn", "tt", "wwww", "iiiii", "hhhhhhh", "zzzzzzzz",
                               "ssssssssss", "j", "fff", "bbbbbbb", "aaaa", "mmmmmmmmmm", "jjjjjjjjjj", "sssss",
                               "yyyyyyyy", "hh", "q", "rrrrrrrrr", "mmmmmmmm", "wwwww", "www", "rrr", "lllll",
                               "uuuuuuuuuu", "oo", "jjjjjjjjj", "dddd", "pppp", "hhhhhhhhh", "kk", "gggggggg", "xxxxx",
                               "vvvv", "d", "qqqqqqqqq", "dd", "ggggggggg", "t", "yyyy", "bbb", "yyyyyyyyyy", "tttttt",
                               "ccccc", "aa", "eeeeee", "llllll", "kkkkkkkkkk", "sssssssss", "i", "hhhhhh",
                               "oooooooooo", "wwwwww", "ooooooooo", "zzzz", "k", "hhhhhhhh", "aaaaa", "mmmmm"};
    const vector<string> results{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                                 "aaaaaaaaaa"};
    CHECK_THAT(leetcode_212::findWords(board, words), UnorderedEquals<string>(results));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_212_TEST_HPP
