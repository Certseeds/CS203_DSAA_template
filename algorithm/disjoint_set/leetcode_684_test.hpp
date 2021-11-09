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
//@Tag 并查集
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP

#include <catch_main.hpp>
#include <vector>
#include <string>

namespace leetcode_684 {
using std::string;
using std::vector;
using Catch::Matchers::Equals;

struct leetcode_684 {
    static vector<int> findRedundantConnection(const vector<vector<int>> &edges);
};

TEST_CASE("1 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {1, 3},
                                        {2, 3}};
    const vector<int32_t> results{2, 3};
    CHECK_THAT(leetcode_684::findRedundantConnection(edges), Equals(results));
}

TEST_CASE("2 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {2, 3},
                                        {3, 4},
                                        {1, 4},
                                        {1, 5}};
    const vector<int32_t> results{1, 4};
    CHECK_THAT(leetcode_684::findRedundantConnection(edges), Equals(results));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP
