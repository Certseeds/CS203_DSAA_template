/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template

 * @Author: nanos
 * @Date: 2021-06-08 20:26:06
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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP

#include "build_graph.hpp"

namespace graph::flow {

struct flink : public link {
    int32_t flow{-1};

    flink(int32_t end_, int32_t cost_, int32_t flow_) : link(end_, cost_), flow(flow_) {}
};

using f_adjlist = vector<vector<flink>>;

f_adjlist build_f_adjlist(const adjlist &table);

class flow final {
public:
    f_adjlist table; // graph本身
    int32_t Sn{-1};// 源点
    int32_t Tn{-1};// 汇点
    int32_t result{0}; // 结果
    flow(const adjlist &table_, int32_t Sn_, int32_t Tn_);

    void maxflow_ek(); //求取最大流结果
};
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP
