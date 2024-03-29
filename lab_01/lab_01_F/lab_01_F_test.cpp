// SPDX-License-Identifier: AGPL-3.0-or-later
/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2023-09-16 01:49:25
 * @LastEditors: nanoseeds
 */
/*
CS203_DSAA_template
Copyright (C) 2020-2023 nanoseeds
*/
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <iostream>

#include "lab_01_F.cpp"

std::string getFilePath() noexcept { return "./../../../lab_01/lab_01_F/resource/"; }
const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_01_F {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 01_F]") {
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
// CatchV3似乎不再支持[.]隐藏, 因此将sequence置为[1,0],隐藏输入
TEST_CASE("test case with sequence", "[test 01_F]") {
    CS203_sequence sequence{1, 0, 0}; // // 基础设定,[1,1]
    sequence.set_postfix_of_datain("data.in"); // 输入数据后缀,默认为 data.in
    sequence.set_postfix_of_dataout("data.out"); // except输出数据后缀,默认为 data.out
    sequence.set_postfix_of_testout("test.out"); // 测试输出数据后缀,默认为 test.out
    const auto files_name = sequence.get_files(true);
    // 获取一个std::tuple<string,string,string> ,
    // 其中每个tuple内为 `输入数据`,`except输出数据`,`测试输出数据`名.
    for (const auto &file_name: files_name) {
        string datain, dataout, testout; // 声明
        tie(datain, dataout, testout) = file_name; // 解包
        {
            const CS203_redirect cr{datain, testout}; // 重定向输入,输出
            main();
            // 用括号括住是为了让CS203_redirect在这里被析构,停止重定向
        }
        CHECK(compareFiles(testout, dataout));
    }
}
}
#endif //CS203_DSAA_TEST_MACRO
