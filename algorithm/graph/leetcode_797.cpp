// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_797_test.hpp"
#include <set>

namespace leetcode_797 {
using std::set;

vector<vector<int32_t>> leetcode_797::allPathsSourceTarget(const vector<vector<int32_t>> &graph) {
    // bfs
    vector<vector<int32_t>> will_return;
    set<vector<int32_t>> re_org;
    vector<vector<int32_t>> temp;
    temp.push_back(vector<int32_t>{0});
    const size_t aim = graph.size() - 1;
    for (size_t i{0}; i < aim; i++) {
        vector<vector<int>> replace;
        for (const auto &j: temp) {
            vector<int> added(j);
            added.push_back(0);
            const int32_t where = j.back();
            const auto j_size = j.size();
            for (const auto k: graph[where]) {
                added[j_size] = k;
                if (static_cast<size_t>(k) == aim) {
                    re_org.insert(added);
                } else {
                    replace.push_back(added);
                }
            }
        }
        if (replace.empty()) {
            break;
        }
        temp = replace;
    }
    will_return.reserve(re_org.size());
    for (const auto &iter: re_org) {
        will_return.push_back(iter);
    }
    return will_return;
}

vector<vector<int32_t>> leetcode_797::allPathsSourceTarget2(const vector<vector<int32_t>> &graph) {
    vector<vector<int32_t>> answer{};
    vector<int32_t> path{0};
    const auto aim = static_cast<int32_t>(graph.size() - 1);
    const std::function<void(int32_t)> dfs = [&answer, &path, &graph, &dfs, &aim](int32_t now) {
        if (now == aim) {
            answer.push_back(path);
            return;
        }
        for (const auto ele: graph[now]) {
            path.push_back(ele);
            dfs(ele);
            path.pop_back();
        }
    };
    dfs(0);
    return answer;
}
}
