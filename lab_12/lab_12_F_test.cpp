/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-06-11 11:10:05
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021 nanoseeds

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
#ifdef CS203_DSAA_TEST_MACRO

#include <tuple>
#include <vector>
#include <iostream>
#include <catch_main.hpp>

#include "lab_12_F.cpp"

string CS203_redirect::file_paths = "./../../lab_12/lab_12_F_data/";

namespace lab_12_F{

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 12 F]") {
    const auto output_data = cal(std::make_tuple(114, 514));
    CHECK(output_data == 628);
    CHECK(1 + 2 == 3);
    vector <int32_t> vec{2, 7, 11, 15};
    SECTION("CHECK_THAT 1") {
        CHECK_THAT(vec, Contains<int>({2}));
    }SECTION("vec matcher") {
        CHECK_THAT(vec, UnorderedEquals<int>({15, 11, 7, 2}));
    }
}
// 因为[.],所以下面这个被隐藏了,确保需要重定向输入输出时,请删除`[.]`
TEST_CASE("test case with sequence", "[test 12 F][.]") {
    CS203_sequence sequence{1, 1, 0}; // // 基础设定,[1,1]
    sequence.set_postfix_of_datain("data.in"); // 输入数据后缀,默认为 data.in
    sequence.set_postfix_of_dataout("data.out"); // except输出数据后缀,默认为 data.out
    sequence.set_postfix_of_testout("test.out"); // 测试输出数据后缀,默认为 test.out
    const auto files_name = sequence.get_files(true);
    // 获取一个std::tuple<string,string,string> ,
    // 其中每个tuple内为 `输入数据`,`except输出数据`,`测试输出数据`名.
    for (const auto &file_name : files_name) {
        string datain, dataout, testout; // 声明
        tie(datain, dataout, testout) = file_name; // 解包
        {
            CS203_redirect cr{datain, testout}; // 重定向输入,输出
            main();
            // 用括号括住是为了让CS203_redirect在这里被析构,停止重定向
        }
        CHECK(compareFiles(testout, dataout));
    }
}
}
#endif //CS203_DSAA_TEST_MACRO