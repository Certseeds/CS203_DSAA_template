/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-21 21:44:25
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
#include <iostream>
#include "catch_main.hpp"
#include "lab_00_D.cpp"

string CS203_redirect::file_paths = "./../../lab_00/lab_00_D_data/";
namespace lab_00_D {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 00 D]") {
    const CS203_redirect cr{"01.data.in"};
    // 重定向开始,开始run
    auto input_data = read();
    cal(input_data);
    // 重定向结束
}

TEST_CASE("test case 2", "[test 00 D]") {
    SECTION("do") {
        const CS203_redirect cr{"01.data.in", "01.test.out"};
        auto input_data = read();
        cal(input_data);
    }SECTION("compare files") {
        CHECK(compareFiles("01.test.out", "01.data.out"));
    }
}
}

#endif //CS203_DSAA_TEST_MACRO