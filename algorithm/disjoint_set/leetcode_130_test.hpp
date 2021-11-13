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
//@Tag disjoint_set
//@Tag 深度优先搜索
//@Tag DFS
//@Tag 广度优先搜索
//@Tag BFS

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP

#include <catch_main.hpp>
#include <vector>
#include <string>

namespace leetcode_130 {
using std::string;
using std::vector;
using Catch::Matchers::Equals;
enum GRID : char {
    WATER = 'X',
    LAND = 'O',
    KEEP_LAND = 'K',
};

struct leetcode_130 {
    static void solve(vector<vector<char>> &board);
};

TEST_CASE("1 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {WATER, WATER, WATER, WATER},
            {WATER, LAND,  LAND,  WATER},
            {WATER, WATER, LAND,  WATER},
            {WATER, LAND,  WATER, WATER},
    };
    const vector<vector<char>> results{
            {WATER, WATER, WATER, WATER},
            {WATER, WATER, WATER, WATER},
            {WATER, WATER, WATER, WATER},
            {WATER, LAND,  WATER, WATER},
    };
    leetcode_130::solve(edges);
    CHECK_THAT(results, Equals(edges));
}

TEST_CASE("2 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {WATER}
    };
    const vector<vector<char>> results{
            {WATER}
    };
    leetcode_130::solve(edges);
    CHECK_THAT(results, Equals(edges));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP
