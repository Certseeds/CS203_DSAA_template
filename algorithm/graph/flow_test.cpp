/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-06-08 23:10:45
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
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

#include <catch_main.hpp>
#include "flow.hpp"

namespace graph::flow {

TEST_CASE("test max flow 1", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist({{{1, 3, 30}, {2, 1, 30}, {2, 3, 20}, {4, 2, 30}, {4, 3, 20}}}, 4);
    flow origin{adjlist_obj, 4, 3};
    origin.maxflow_ek();
    static constexpr const auto result{50};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 2", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 40}, {1, 4, 20}, {2, 4, 20}, {2, 3, 30}, {3, 4, 10}}
            }, 4);
    flow origin{adjlist_obj, 1, 4};
    origin.maxflow_ek();
    static constexpr const auto result{50};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 3", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 10}, {2, 3, 5}, {2, 4, 15}, {1, 4, 5}, {4, 3, 10}}
            }, 4);
    flow origin{adjlist_obj, 1, 3};
    origin.maxflow_ek();
    static constexpr const auto result{15};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 4", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 40}, {2, 4, 30}, {1, 3, 60}, {2, 3, 20}, {3, 5, 40}, {4, 5, 50}}
            }, 5);
    flow origin{adjlist_obj, 1, 5};
    origin.maxflow_ek();
    static constexpr const auto result{70};
    CHECK(result == origin.result);
}
}