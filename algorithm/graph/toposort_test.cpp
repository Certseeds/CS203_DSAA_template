// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.RRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WA

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <catch_main.hpp>
#include "toposort.hpp"
#include <iostream>

namespace graph {
namespace toposort {
using Catch::Matchers::Equals;

TEST_CASE("2 [test graph toposort]", "[test graph toposort]") {
    const auto obj = graphlist({{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}}, 4);
    SECTION("one toposort") {
        const auto result = obj.toposort();
        std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
        std::cout << std::endl;
    }SECTION("all toposort order") {
        const auto results = obj.toposorts();
        for (const auto &result: results) {
            std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
            std::cout << std::endl;
        }
    }
}

TEST_CASE("1 [test graph toposort]", "[test graph toposort]") {
    const auto obj = graphlist({{
                                        {1, 3, 8},
                                        {2, 4, 6},
                                        {3, 5, 9},
                                        {5, 6, 7},
                                        {4, 6, 8},
                                        {6, 7, 9},
                                        {7, 8, 9},
                                        {8, 9, 10},
                                }}, 9);
    const auto results = obj.toposorts();
    for (const auto &result: results) {
        std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
        std::cout << std::endl;
    }
}
}
}