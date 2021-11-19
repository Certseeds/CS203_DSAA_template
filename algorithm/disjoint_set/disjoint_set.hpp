//
// Created by nanos on 2021/11/9.
//

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP

#include <vector>
#include <string>

namespace disjoint_set {
using std::vector;

class disjoint_set final {
private:
    std::vector<size_t> fa; // 记录father
    std::vector<size_t> points; // 记录子节点
public:
    explicit disjoint_set(size_t size);

    size_t find(size_t x);

    void merge(size_t x, size_t y);

    void mergeHeur(size_t x, size_t y);
};
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
