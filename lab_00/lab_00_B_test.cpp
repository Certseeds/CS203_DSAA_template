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


#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <iostream>
#include "lab_00_B.cpp"

std::string getFilePath() noexcept { return "./../../lab_00/lab_00_B_data/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_B {
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 00 B]") {
    auto vec1 = vector<num_type>{8, 1, 2, 3, 4, 5, 6, 7, 1100000};
    for (const auto &i: vec1) {
        CHECK(cal(i) == brute_force(i));
    }
}

TEST_CASE("test case 2", "[test 00 B]") {
    auto vec1 = vector<num_type>{1, 2, 3, 4, 5, 6, 7, 1100000};
    auto result = cal_warpper(vec1);
    auto what_we_want = vector<num_type>{1, 4, 10, 20, 35, 56, 84, 221833938333700000};
    CHECK_THAT(result, Equals<num_type>({1, 4, 10, 20, 35, 56, 84, 221833938333700000}));
    CHECK_THAT(result, Equals(what_we_want));
}
}
#endif //CS203_DSAA_TEST_MACRO