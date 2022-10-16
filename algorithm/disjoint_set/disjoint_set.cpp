//
// Created by nanos on 2021/11/9.
//

#include <vector>
#include <numeric>
#include <iostream>
#include "disjoint_set.hpp"

namespace disjoint_set {
using std::string;
using std::cout, std::endl;
namespace impl {
class set : public disjoint_set {
protected:
    std::vector<size_t> fa; // 记录father
    std::vector<size_t> points; // 记录子节点
public:
    explicit set(size_t size) : fa(vector<size_t>(size + 1, -1)) {
        this->points = vector<size_t>(size + 1, 0);
        // 0号元素弃用
        // from 1 to ${size}
        // value is 1 to ${size}
        std::iota(fa.begin(), fa.end(), 0);
    }

    size_t find(size_t x) override {
        if (this->fa[x] != x) {
            this->fa[x] = find(fa[x]);
        }
        return this->fa[x];
    }

    void merge(size_t x, size_t y) override {
        const auto xfa = find(x), yfa = find(y);
        if (xfa == yfa) {
            return;
        }
        fa[xfa] = yfa;
    }

    void mergeHeur(size_t x, size_t y) override {
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
};
}

std::unique_ptr<disjoint_set> getDisjointSet(size_t x) {
    return std::make_unique<impl::set>(x);
}

}
