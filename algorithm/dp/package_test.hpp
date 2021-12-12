/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP

#include "package.hpp"
#include <catch_main.hpp>

namespace zero_one_package {
TEST_CASE("1 [test dp_package]", "[test dp_package]") {
    const vector<something> things{
            something{2, 4}, something{1, 2}, something{3, 3},
    };
    static constexpr const size_t weight = 4;
    Package package{things, weight};
    /**
     * cost 1 to things[1], get 2 <br>
     * cost 2 to things[0], get 4 <br>
     * Sums: cost 3, get 6
     * */
    static constexpr const size_t unFullResult = 6;
    CHECK(unFullResult == package.solve<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveSaveSpace<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveOneLine<allow_unfull::ALLOW>());
    /**
     * cost 1 to things[1], get 2 <br>
     * cost 3 to things[2], get 3 <br>
     * Sums: cost 4, get 5
     * */
    static constexpr const size_t FullResult = 5;
    CHECK(FullResult == package.solve<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveSaveSpace<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveOneLine<allow_unfull::UN_ALLOW>());
}
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP
