/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-04-12 23:57:10
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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_PATH_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_PATH_HPP

#include <cstdint>
#include <vector>

namespace graph {
using std::vector;

struct link {
    int32_t end, cost;

    link(int32_t end_, int32_t cost_) : end(end_), cost(cost_) {}
};

using adjacent_table = vector<vector<link>>;

// build should not be all empty but each vector is empty,
adjacent_table build_adjacent_table(const vector<vector<int32_t>> &input, int32_t node_num);

bool check_graph_cost_all_positive(const vector<vector<int32_t>> &input);
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_PATH_HPP