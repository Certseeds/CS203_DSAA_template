/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
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
#include <cassert>
#include <cstring>
#include <queue>
#include <utility>
#include "flow.hpp"

namespace graph::flow {
using std::queue;

void flow::maxflow_ek() {
    if (this->Sn == this->Tn) {
        this->result = 0;
        return;
    }
    vector<int32_t> lastpoint(this->table.size(), 0); // lastpoint[i],到i点的上一条边
    vector<int32_t> flows(this->table.size(), 0); // flows[i],到i点的流量
    while (true) {
        std::memset(&flows[0], 0, sizeof(int32_t) * flows.size());
        queue<int32_t> que;
        que.push(this->Sn);
        flows[Sn] = 0x3f3f3f3f;
        while (!que.empty()) {
            int32_t order = que.front();
            que.pop();
            for (const auto &item: this->table[order]) {
                if (flows[item.end] != 0) {
                    continue;
                }
                if (item.cost > item.flow) {
                    lastpoint[item.end] = order;
                    flows[item.end] = std::min(flows[order], item.cost - item.flow);
                    que.push(item.end);
                }
            }
            if (flows[this->Tn] != 0) {
                break;
            }
        }
        if (flows[this->Tn] == 0) {
            break;
        }
        const auto search = [this](int begin, int end) {
            for (int32_t i{0}; static_cast<size_t>(i) < this->table[begin].size(); i++) {
                if (this->table[begin][i].end == end) {
                    return i;
                }
            }
            return -1;
        };
        for (auto end = this->Tn; end != this->Sn; end = lastpoint[end]) {
            const auto begin = lastpoint[end];
            table[begin][search(begin, end)].flow += flows[this->Tn];
            table[end][search(end, begin)].flow -= flows[this->Tn];
        }
        this->result += flows[this->Tn];
    }
}

/**
 * 这里注意,默认input格式是从1开始对节点计数,所以对Sn,Tn各减一
**/
flow::flow(const adjlist &table_, int32_t Sn_, int32_t Tn_) : table(build_f_adjlist(table_)), Sn(Sn_ - 1),
                                                              Tn(Tn_ - 1) {}

f_adjlist build_f_adjlist(const adjlist &table) {
    f_adjlist will_return(table.size(), vector<flink>{});
    for (size_t i{0}; i < table.size(); ++i) {
        for (const auto &item: table[i]) {
            will_return[i].emplace_back(item.end, item.cost, 0);
            will_return[item.end].emplace_back(i, 0, 0);
        }
    }
    return will_return;
}
}