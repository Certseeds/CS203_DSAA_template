/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-09-11 15:27:10
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

#include "lab_welcome_C.cpp"

std::string getFilePath() noexcept {
    return "./../../lab_welcome/lab_welcome_C_data/";
}

namespace lab_welcome_C {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test welcome C]") {
    CHECK(cal_detail(1) == "2");
    CHECK(cal_detail(2) == "3");
    CHECK(cal_detail(3) == "6");
    CHECK(cal_detail(4) == "22");
    CHECK(cal_detail(5) == "23");
    CHECK(cal_detail(6) == "26");
    CHECK(cal_detail(7) == "32");
    CHECK(cal_detail(8) == "33");
    CHECK(cal_detail(9) == "36");
    CHECK(cal_detail(10) == "62");
    CHECK(cal_detail(100) == "6262");
    CHECK(cal_detail(1000) == "636362");
    CHECK(cal_detail(10000) == "222236662");
    CHECK(cal_detail(100000) == "22362622262");
    CHECK(cal_detail(1000000) == "2323266262362");
    CHECK(cal_detail(999999999) == "3226236233626363336");
    CHECK(cal_detail(1000000000) == "3226236233626363362");
}
}
#endif //CS203_DSAA_TEST_MACRO