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
#include <catch_main.hpp>
#include "basic.cpp"

namespace binary_search {
using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;


TEST_CASE("lower_bound", "[test basic binary search]") {
    const vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    const vector<tuple<num_t, num_t>> input_result = {
            {1, 0},
            {2, 2},
            {3, 3},
            {4, 4},
            {5, 7},
            {6, 9}};
    for (const auto &i: input_result) {
        num_t input{0}, output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound(vec, 0, vec.size(), input));
    }
}

TEST_CASE("any_equal", "[test basic binary search]") {
    const vector<num_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    const vector<tuple<num_t, num_t, num_t>> input_result = {
            {1, 0,  1},
            {2, 1,  3},
            {3, 3,  6},
            {4, 6,  10},
            {5, 10, 15},
            {6, 15, 16}};
    // 0 2 4 8 12 15
    for (const auto &i: input_result) {
        num_t input{0};
        num_t left{0};
        num_t right{0};
        tie(input, left, right) = i;
        num_t result = any_equal(vec, 0, static_cast<num_t>(vec.size()), input);
        CHECK(result >= left);
        CHECK(result < right);
    }
}


TEST_CASE("upper_bound", "[test basic binary search]") {
    const vector<num_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    const vector<tuple<num_t, num_t>> input_result = {
            {1, 1},
            {2, 3},
            {3, 6},
            {4, 10},
            {5, 15},
            {6, 16}};
    for (const auto &i: input_result) {
        num_t input{0}, output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound(vec, 0, vec.size(), input));
    }
}


TEST_CASE("lower_bound_warpper", "[test basic binary search]") {
    const vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    const vector<tuple<num_t, num_t>> input_result = {
            {1, -1},
            {2, 1},
            {3, 2},
            {4, 3},
            {5, 6},
            {6, 8}};
    for (const auto &i: input_result) {
        num_t input{0}, output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound_warpper(vec, 0, vec.size(), input));
    }
}


TEST_CASE("upper_bound_warpper", "[test basic binary search]") {
    const vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    const vector<tuple<num_t, num_t>> input_result = {
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 6},
            {5, 8},
            {6, 9}};
    for (const auto &i: input_result) {
        num_t input{0}, output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound_warpper(vec, 0, vec.size(), input));
    }
}
}