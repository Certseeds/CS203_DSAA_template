/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseds
 * @Date: 2020-07-19 19:37:58
 * @LastEditors: nanoseds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020 nanoseds

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
#ifndef CS203_DSAA_TEST_MACRO
#define CS203_DSAA_TEST_MACRO

#include <vector>
#include <iostream>
#include "catch_main.hpp"
#include "lab_00_C.cpp"

using std::cin;
using std::cout;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
string CS203_redirect::file_paths = "./../test/lab_00/lab_00_C_data/";

TEST_CASE("test case 1", "[test 00 C]") {
    CS203_redirect cr{"01.data.in", ""};
    // 重定向开始,开始run
    auto output_data = isBipartite(read());
    // 重定向结束
    CHECK_FALSE(output_data);
}

TEST_CASE("test case 2", "[test 00 C]") {
    CS203_redirect cr{"02.data.in"};
    auto output_data = isBipartite(read());
    CHECK(output_data);
}

TEST_CASE("test case 3", "[test 00 C]") {
    CS203_redirect cr{"03.data.in"};
    auto output_data = isBipartite(read());
    CHECK(output_data);
}

TEST_CASE("test case 4", "[test 00 C]") {
    CS203_redirect cr{"04.data.in"};
    auto output_data = isBipartite(read());
    CHECK_FALSE(output_data);
}

TEST_CASE("test case 5", "[test 00 C]") {
    CS203_redirect cr{"05.data.in"};
    auto output_data = isBipartite(read());
    CHECK_FALSE(output_data);
}

TEST_CASE("test case in loop", "[test 00 C]") {
    const vector<string> strs{
            "01.data.in", "02.data.in",
            "03.data.in", "04.data.in",
            "05.data.in"
    };
    const vector<uint8_t> result{false, true, true, false, false};
    for (int i = 0; i < 5; ++i) {
        CS203_redirect cr{strs[i]};
        auto output_data = isBipartite(read());
        CHECK(output_data == result[i]);
    }
}

TEST_CASE("test case with tuple", "[test 00 C]") {
    const vector<std::tuple<string, output_type>> input_result{
            {"01.data.in", false},
            {"02.data.in", true},
            {"03.data.in", true},
            {"04.data.in", false},
            {"05.data.in", false}
    };
    for (const auto &tup : input_result) {
        string path;
        output_type result;
        tie(path, result) = tup;
        CS203_redirect cr{path};
        auto output_data = isBipartite(read());
        CHECK(output_data == result);
    }
}

#endif //CS203_DSAA_TEST_MACRO