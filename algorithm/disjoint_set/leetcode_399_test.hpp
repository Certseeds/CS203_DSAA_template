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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_399 {
using std::string;
using std::vector;

struct leetcode_399 {
    static vector<double>
    calcEquation(const vector<vector<string>> &equations, const vector<double> &values,
                 const vector<vector<string>> &queries);
};

using Catch::Matchers::ApproxMatcher;
using Catch::Matchers::Approx;

TEST_CASE("1 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "b"},
            {"b", "c"},
    };
    const vector<double_t> values{2.0f,
                                  3.0f};
    const vector<vector<string>> queries{
            {"a", "c"},
            {"b", "a"},
            {"a", "e"},
            {"a", "a"},
            {"x", "x"},
    };
    const vector<double_t> results{6.0f, 0.5f, -1.0f, 1.0f, -1.0f};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("2 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "b"},
    };
    const vector<double_t> values{0.5f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"b", "a"},
            {"a", "c"},
            {"x", "y"},
    };
    const vector<double_t> results{0.5f, 2.0f, -1.0f, -1.0f};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("3 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a",  "b"},
            {"b",  "c"},
            {"bc", "cd"}
    };
    const vector<double_t> values{1.5f, 2.5f, 5.0f};
    const vector<vector<string>> queries{
            {"a",  "c"},
            {"c",  "b"},
            {"bc", "cd"},
            {"cd", "bc"},
    };
    const vector<double_t> results{3.75f, 0.4f, 5.0f, 0.2f};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}


TEST_CASE("5 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"x1", "x2"},
            {"x2", "x3"},
            {"x1", "x4"},
            {"x2", "x5"},
    };
    const vector<double_t> values{3.0f, 0.5f, 3.4f, 5.6f};
    const vector<vector<string>> queries{
            {"x2", "x4"},
            {"x1", "x5"},
            {"x1", "x3"},
            {"x5", "x5"},
            {"x5", "x1"},
            {"x3", "x4"},
            {"x4", "x3"},
            {"x6", "x6"},
            {"x0", "x0"},
    };
    const vector<double_t> results{1.13333, 16.8, 1.5, 1.0, 0.05952, 2.26667, 0.44118, -1.0, -1.0};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("4 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "e"},
            {"b", "e"},
    };
    const vector<double_t> values{4.0f, 3.0f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"e", "e"},
            {"x", "x"},
    };
    const vector<double_t> results{1.3333f, 1.0f, -1.0f};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("6 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"e", "a"},
            {"e", "b"},
    };
    const vector<double_t> values{3.0f, 4.0f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"e", "e"},
            {"x", "x"},
    };
    const vector<double_t> results{1.3333f, 1.0f, -1.0f};
    CHECK_THAT(results, Approx(leetcode_399::calcEquation(edges, values, queries)).epsilon(0.01f));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP
