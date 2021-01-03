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
string CS203_redirect::file_paths = "./../../../test/lab_00/lab_00_C_data/";
/*
 * Test case 1 -> Test case 5
 * 目的是为了展示只使用CS203_redirect的情况下
 * 应该如何只重定向输入,不重定向输出.
 * */
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
/*目的在于展示,使用循环来精简Test case1~5中的工作量*/
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
/*目的在于展示,std::tuple的打包能力*/
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
/* 目的在于展示 CS203_sequence 生成重定向相关文件名的能力
 * */
TEST_CASE("test case with sequence", "[test 00 C]") {

    CS203_sequence sequence(1, 5, 2);
    // 前缀被默认设定为 空串 ""
    sequence.set_postfix_of_datain("data.in"); // 输入数据后缀,默认为 data.in
    sequence.set_postfix_of_dataout("data.out"); // except输出数据后缀,默认为 data.out
    sequence.set_postfix_of_testout("test.out"); // 测试输出数据后缀,默认为 test.out
    const auto files_name = sequence.get_files(true);
    // 获取一个std::tuple<string,string,string> ,
    // 其中每个tuple内为 `输入数据`,`except输出数据`,`测试输出数据`名.
    for (const auto &filesName : files_name) {
        string datain, dataout, testout; // 声明
        tie(datain, dataout, testout) = filesName; // 解包
        {
            CS203_redirect cr{datain, testout}; // 重定向输入,输出
            main2();
            // 用括号括住是为了让CS203_redirect在这里被析构,停止重定向
        }
        CHECK(compareFiles(testout, dataout));
    }
}


#endif //CS203_DSAA_TEST_MACRO