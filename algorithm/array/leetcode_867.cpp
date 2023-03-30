// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_867_test.hpp"

namespace leetcode_867 {
vector <vector<int32_t>> leetcode_867::transpose(const vector <vector<int32_t>> &A) {
    const auto m{A.size()};
    if (m == 0) {
        return {};
    }
    const auto n{A[0].size()};
    vector <vector<int32_t>> will_return(n, vector<int32_t>(m));
    for (size_t i{0}; i < n; ++i) {
        for (size_t j{0}; j < m; ++j) {
            will_return[i][j] = A[j][i];
        }
    }
    return will_return;
}
}
