//
// Created by nanos on 2021/11/9.
//

#include <vector>
#include <numeric>
#include "disjoint_set.hpp"

namespace disjoint_set {
using std::string;

disjoint_set::disjoint_set(const size_t size) : fa(vector<size_t>(size + 1, -1)), points(vector<size_t>(size + 1, 0)) {
    // 0号元素弃用
    // from 1 to ${size}
    // value is 1 to ${size}
    std::iota(fa.begin(), fa.end(), 0);
}

size_t disjoint_set::disjoint_set::find(size_t x) {
    if (this->fa[x] != x) {
        this->fa[x] = find(fa[x]);
    }
    return this->fa[x];
}

void disjoint_set::merge(size_t x, size_t y) {
    const auto xfa = find(x),
            yfa = find(y);
    if (xfa == yfa) {
        return;
    }
    fa[xfa] = yfa;
}

void disjoint_set::mergeHeur(size_t x, size_t y) {
    const auto xfa = find(x),
            yfa = find(y);
    if (xfa == yfa) {
        return;
    }
    if (points[xfa] > points[yfa]) {
        fa[yfa] = xfa;
        points[xfa] = points[xfa] + points[yfa];
    } else {
        fa[xfa] = yfa;
        points[yfa] = points[xfa] + points[yfa];
    }
}
}
