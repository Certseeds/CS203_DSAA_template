//
// Created by nanos on 2022/1/2.
//

#ifndef CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP

#include <vector>
#include <cstddef>
#include <cstdint>

class TreeNodeMulti {
public:
    int32_t val;
    vector<TreeNodeMulti *> children;

    Node() = default;

    Node(int _val) : Node(_val, {}) {};

    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};


#endif //CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_MULTI_HPP
