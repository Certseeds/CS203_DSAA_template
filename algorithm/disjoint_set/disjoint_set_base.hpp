// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP

#include <vector>
#include <class_helper/nonable.hpp>

namespace disjoint_set_base {
using std::vector;

class DisjointSetBase : private nonCopyMoveAble {
protected:
    std::vector<size_t> fa; // 记录father
    std::vector<size_t> points; // 记录子节点
public:
    explicit DisjointSetBase(size_t size) : fa(vector<size_t>(size + 1, -1)) {};

    virtual size_t find(size_t x) = 0;

    virtual void merge(size_t x, size_t y) = 0;

    virtual void mergeHeur(size_t x, size_t y) = 0;

};
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP
