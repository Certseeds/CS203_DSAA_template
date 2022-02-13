/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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

#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CATCH_MAIN_H

#include <catch_main.hpp>

#pragma message("import catch_main.hpp")

#else
#pragma message("use pre-compiled")
#endif


#include <iostream>
#include <tuple>
#include <vector>

#include "lab_00_A.cpp"

std::string getFilePath() noexcept { return "./../../lab_00/lab_00_A_data/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_A {
using std::cin;
using std::cout;
using std::tie;
using std::tuple;
using std::vector;

TEST_CASE("test case 1", "[test 00 A]") {
    const auto output1 = cal(std::make_tuple(0, 0));
    auto output2 = cal(std::make_tuple(100000, 100000));
    CHECK_FALSE(output1);
    CHECK(200000 == output2);
}

TEST_CASE("test case 2", "[test 00 A]") {
    auto output1 = cal(std::make_tuple(0, 100000));
    auto output2 = cal(std::make_tuple(100000, 0));
    CHECK(100000 == output1);
    CHECK(100000 == output2);
}

TEST_CASE("test case 3", "[test 00 A]") {
    std::random_device rd{};
    const auto gen = std::mt19937{rd()};
    const std::uniform_real_distribution<> dis{0, 100000};
    auto randfun = std::bind(dis, gen); // 产生一个函数,返回0-10000的随机数
    for (int i = 0; i < 20; i++) {
        const int a = randfun(), b = randfun();
        CHECK(cal(std::make_tuple(a, b)) ==
              cal(std::make_tuple(b, a)));          // 确认对偶性
        CHECK(a + b == cal(std::make_tuple(a, b))); // 确认正确性
    }
}

TEST_CASE("test case 4", "[test 00 A]") {
    const auto output = cal(std::make_tuple(100, 1000));
    CHECK(1100 == output);
}
} // namespace lab_00_A
#endif // CS203_DSAA_TEST_MACRO
