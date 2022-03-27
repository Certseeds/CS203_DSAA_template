// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_684_test.hpp"
#include "disjoint_set.hpp"

namespace leetcode_684 {
using disjoint_set::disjoint_set;

vector<int> leetcode_684::findRedundantConnection(const vector<vector<int>> &edges) {
    const auto edge_sizes{edges.size()};
    disjoint_set jset(edge_sizes);
    for (const auto &edge: edges) {
        if (jset.find(edge[0]) != jset.find(edge[1])) {
            jset.merge(edge[0], edge[1]);
        } else {
            return edge;
        }
    }
    return {};
}

}