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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP

#include <cassert>
#include <queue>
#include "build_graph.hpp"

namespace graph {
namespace dijistra {
using std::vector;
using std::priority_queue;

class graphlist final {
    vector<vector<link>> graph;
public:
    graphlist(const vector<vector<int32_t>> &input, int32_t node_num) : graph(node_num, vector<link>{}) {
        check_graph_cost_all_positive(input);
        for (const auto &item: input) {
            graph[item[0] - 1].emplace_back(item[1] - 1, item[2]);
        }
    }

    inline size_t size() const { return graph.size(); }

    inline auto at(size_t size) const { return graph.at(size); }

    [[nodiscard]] vector<int32_t> dijkstra(int32_t begin_node) const {
        begin_node -= 1;
        vector<int32_t> results(this->size(), 0x3f3f3f3f);
        results[begin_node] = 0;
        // PS: in this part,if begin_node count from 1, begin_node should -= 1
        static constexpr const auto cmp{
                [](const link &v1, const link &v2) {
                    return v1.cost > v2.cost;
                }
        };
        priority_queue<link, vector<link>, decltype(cmp)> priorityQueue{cmp};
        priorityQueue.emplace(begin_node, -1);
        while (!priorityQueue.empty()) {
            const auto head = priorityQueue.top();
            priorityQueue.pop();
            for (auto &i: this->at(head.end)) {
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
};

}
}
#endif // CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP
