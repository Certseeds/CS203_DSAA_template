// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_933_test.hpp"
#include <queue>

namespace leetcode_933 {
using std::queue;

class RecentCounterNormal : public RecentCounter {
private:
    queue<int> que;
public:
    RecentCounterNormal() = default;

    int ping(int t) override {
        que.push(t);
        while (que.front() < t - 3000) {
            que.pop();
        }
        return que.size();
    }
};

RecentCounter *leetcode_933::pure() {
    return new RecentCounterNormal();
}
}