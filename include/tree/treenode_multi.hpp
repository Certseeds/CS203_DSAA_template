// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/

#ifndef CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP

#include <utility>
#include <vector>
#include <cstddef>
#include <cstdint>

namespace TREE_NODE {

class TreeNodeMulti final : private nonCopyMoveAble {
public:
    int32_t val{};
    vector<TreeNodeMulti *> children;

    TreeNodeMulti() = default;

    explicit TreeNodeMulti(int _val) : TreeNodeMulti(_val, {}) {};

    TreeNodeMulti(int _val, vector<TreeNodeMulti *> _children) : val(_val), children(std::move(_children)) {}
};
}


#endif //CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP
