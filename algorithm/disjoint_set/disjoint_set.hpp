// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP

#include "disjoint_set_base.hpp"
#include <string>

namespace disjoint_set {
using std::vector;
using disjoint_set_base::DisjointSetBase;

class disjoint_set final : public DisjointSetBase {
private:
    using base = disjoint_set_base::DisjointSetBase;
public:
    explicit disjoint_set(size_t x);

    size_t find(size_t x) override;

    void merge(size_t x, size_t y) override;

    void mergeHeur(size_t x, size_t y) override;
};
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
