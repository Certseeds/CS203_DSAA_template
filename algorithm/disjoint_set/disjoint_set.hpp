// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP

#include <string>
#include <memory>

#include "class_helper/nonable.hpp"

namespace disjoint_set {
using std::vector;

class disjoint_set : private nonCopyMoveAble{
public:
    virtual ~disjoint_set() = default;

    virtual size_t find(size_t x) = 0;

    virtual void merge(size_t x, size_t y) = 0;

    virtual void mergeHeur(size_t x, size_t y) = 0;
};

std::unique_ptr<disjoint_set> getDisjointSet(size_t x);

}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
