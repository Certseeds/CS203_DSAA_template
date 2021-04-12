/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-04-12 23:56:04
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
#include "dijistra.hpp"

namespace graph {
using std::vector;
using std::priority_queue;

vector<int32_t> dijkstra(const vector<vector<int32_t>> &input, int32_t node_num, int32_t begin_node) {
    check_graph_cost_all_positive(input);
    adjacent_table graph = build_adjacent_table(input, node_num);
    begin_node -= 1;
    vector<int32_t> results(node_num, 0x3f3f3f3f);
    results[begin_node] = 0;
    // PS: in this part,if begin_node count from 1, begin_node should -= 1
    const auto cmp{
            [](const link &v1, const link &v2) {
                return v1.cost > v2.cost;
            }
    };
    priority_queue<link, vector<link>, decltype(cmp)> priorityQueue{cmp};
    priorityQueue.push(link(begin_node, -1));
    while (!priorityQueue.empty()) {
        auto head = priorityQueue.top();
        priorityQueue.pop();
        for (auto &i: graph[head.end]) {
            const auto val = results[head.end] + i.cost;
            if (results[i.end] >= val) {
                results[i.end] = val;
                priorityQueue.push(i);
            }
        }
    }
    // then, in result is the distance from begin_node to i
    return results;
}
}
