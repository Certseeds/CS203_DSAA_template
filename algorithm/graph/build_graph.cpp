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
#include <cassert>
#include "build_graph.hpp"

namespace graph {

adjacent_table build_adjacent_table(const vector<vector<int32_t>> &input, int32_t node_num) {
    adjacent_table graph(node_num, vector<link>{});
    for (const auto &item: input) {
        graph[item[0]-1].emplace_back(item[1]-1, item[2]);
        // 这里注意,如果input格式是从1开始对节点计数,则需要对item[0],item[1]各减一
    }
    return graph;
}

bool check_graph_cost_all_positive(const vector<vector<int32_t>> &input) {
    for (const auto &item: input) {
        assert(item.size() == 3);
        assert(item[2] >= 0);
    }
    return false;
}

}