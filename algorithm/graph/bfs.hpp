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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BFS_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BFS_HPP

#include "build_graph.hpp"
#include <queue>

namespace graph {
namespace bfs {
using std::vector;
using std::queue;
enum class STATE {
    WHITE,
    GRAY,
    BLACK,
};

class graphlist final {
    struct node {
        const size_t order;
        STATE state{STATE::WHITE};
        node *prev{nullptr};
        size_t distance{NO_V};
        vector<link> links;

        explicit node(size_t node) : order(node) {}

        node(const node &node_) = default;
    };

    vector<node> graph;
    using invoke = std::function<void(const node &)>;
public:
    static constexpr const size_t NO_V{0x3f3f3f3f};

    graphlist(const vector<vector<int32_t>> &input, int32_t node_num) {
        check_graph_cost_all_positive(input);
        graph.reserve(node_num);
        for (int32_t i{0}; i < node_num; ++i) {
            graph.emplace_back(i);
        }
        for (const auto &item: input) {
            graph[item[0] - 1].links.emplace_back(item[1] - 1, item[2]);
        }
    }

    inline size_t size() const { return graph.size(); }

    inline auto at(size_t size) const { return graph.at(size).links; }

    vector<node> bfs(size_t begin_) const {
        begin_ -= 1;
        const auto begin = begin_;
        static const invoke func = [](const node &n) { std::cout << n.order << " " << n.distance << std::endl; };
        auto nodes = graph;
        nodes[begin].distance = 0;
        nodes[begin].state = STATE::GRAY;
        queue<size_t> que({nodes[begin].order});
        //func(nodes[begin]);
        while (!que.empty()) {
            const auto head_order = que.front();
            que.pop();
            for (const auto &[end, cost]: this->at(head_order)) {
                if (nodes[end].state == STATE::WHITE) {
                    nodes[end].state = STATE::GRAY;
                    nodes[end].prev = &nodes[head_order];
                    nodes[end].distance = nodes[head_order].distance + cost;
                    que.push(end);
                    //func(nodes[end]);
                }
            }
            nodes[head_order].state = STATE::BLACK;
        }
        return nodes;
    }
};

}
}
#endif // CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BFS_HPP
