// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos
*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_GRAPH_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_GRAPH_HPP

#include <cstdint>
#include <vector>
#include <cstddef>

namespace graph {
using std::vector;

struct link {
    int32_t end{-1}, cost{-1};

    link(int32_t end_, int32_t cost_) : end(end_), cost(cost_) {}
};

using adjlist = vector<vector<link>>;

// build should not be all empty but each vector is empty,
adjlist build_adjlist(const vector<vector<int32_t>> &input, int32_t node_num);

bool check_graph_cost_all_positive(const vector<vector<int32_t>> &input);

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_BUILD_GRAPH_HPP
