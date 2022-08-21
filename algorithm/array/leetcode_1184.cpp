// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1184_test.hpp"

namespace leetcode_1184 {

int32_t leetcode_1184::distanceBetweenBusStops(const vector<int32_t> &distance, int32_t start, int32_t destination) {
    if (start > destination) {
        return distanceBetweenBusStops(distance, destination, start);
    }
    int32_t value1{0}, value2{0};
    const auto max_range{distance.size()};
    for (int32_t i{start}; i < destination; ++i) {
        value1 += distance[i];
    }
    for (size_t i = destination; i < max_range; ++i) {
        value2 += distance[i];
    }
    for (int32_t i{0}; i < start; ++i) {
        value2 += distance[i];
    }
    return std::min(value1, value2);
}


}
