/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_743_test.hpp"
#include <queue>
#include <unordered_set>

namespace leetcode_743 {
using std::priority_queue;
using std::unordered_set;

int32_t leetcode_743::networkDelayTime(const vector<vector<int32_t>> &times, int32_t n, int32_t k) {
    struct time_ {
        int32_t end, cost;

        time_(int32_t end, int32_t cost) : end(end), cost(cost) {}

        bool operator<(const time_ &v2) const { return this->cost > v2.cost; }
    };
    k -= 1;
    vector<vector<time_>> dis(n, vector<time_>{});
    vector<int32_t> results(n, 0x3f3f3f3f);
    for (const auto &time: times) {
        const auto &first = time[0];
        const auto &second = time[1];
        const auto &third = time[2];
        dis[first - 1].emplace_back(second - 1, third);
    }
    priority_queue<time_> priorityQueue{};
    unordered_set<int32_t> uMap{};
    results[k] = 0;
    priorityQueue.emplace(k, -1);
    while (!priorityQueue.empty()) {
        const auto head = priorityQueue.top();
        priorityQueue.pop();
        for (auto &i: dis[head.end]) {
            const auto val = results[head.end] + i.cost;
            if (val < results[i.end]) {
                results[i.end] = val;
                priorityQueue.push(i);
            }
        }
    }
    const int32_t will_return = *std::max_element(std::cbegin(results), std::cend(results));
    return will_return == 0x3f3f3f3f ? -1 : will_return;
}
}