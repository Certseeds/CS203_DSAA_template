/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseds
 * @Date: 2020-07-21 21:44:25
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

#include <tuple>
#include <iostream>
#include "catch_main.hpp"
#include "lab_00_D.cpp"

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
const string test_file_path = "./../test/lab_00/lab_00_D_data/";

TEST_CASE("test case 1", "[test 00 D]") {
    std::streambuf *backup;
    std::ifstream fin;
    fin.open(test_file_path + "01.data.in");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());
    // 重定向开始,开始run
    cal(read());
    // 重定向结束
    cin.rdbuf(backup);
}

TEST_CASE("test case 2", "[test 00 C]") {
    SECTION("do") {
        std::streambuf *strmin_buf = cin.rdbuf();
        std::streambuf *strmout_buf = cout.rdbuf();
        std::ifstream file_in;
        std::ofstream file_out;
        file_in.open(test_file_path + "01.data.in");
        file_out.open(test_file_path + "01.test.out");
        cin.rdbuf(file_in.rdbuf());
        cout.rdbuf(file_out.rdbuf());
        cal(read());
        cin.rdbuf(strmin_buf);
        cout.rdbuf(strmout_buf);
        cout.flush();
    }SECTION("compare files") {
        CHECK(compareFiles(test_file_path + "01.test.out", test_file_path + "01.data.out"));
    }
}

#endif //CS203_DSAA_TEST_MACRO