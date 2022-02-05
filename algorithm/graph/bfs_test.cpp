/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanos

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
#include "bfs.hpp"

namespace graph {
namespace bfs {
using Catch::Matchers::Equals;
// 简简单单一个bfs

TEST_CASE("2 [test graph bfs]", "[test graph bfs]") {
    const auto obj = graphlist({{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}}, 4);
    const auto result = obj.bfs(2);
    CHECK(1 == result[0].distance);
    CHECK(0 == result[1].distance);
    CHECK(1 == result[2].distance);
    CHECK(2 == result[3].distance);
    for (const auto &x: result) {
        CHECK(x.state == STATE::BLACK);
    }
}

TEST_CASE("3-1 [test graph bfs]", "[test graph bfs]") {
    const auto obj = graphlist({{{1, 2, 1}}}, 2);
    const auto result = obj.bfs(1);
    CHECK(0 == result[0].distance);
    CHECK(1 == result[1].distance);
}

TEST_CASE("3-2 [test graph bfs]", "[test graph bfs]") {
    const auto obj = graphlist({{{1, 2, 1}}}, 2);
    const auto result = obj.bfs(2);
    CHECK(graphlist::NO_V == result[0].distance);
    CHECK(0 == result[1].distance);
}
}
}