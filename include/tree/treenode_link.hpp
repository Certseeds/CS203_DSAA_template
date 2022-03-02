// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP

#include "tree/treenode.hpp"
#include <stack>
#include <class_helper/nonable.hpp>

namespace TREE_NODE {
using std::stack;

template<typename T>
class TreeNodeLink final : private nonCopyMoveAble {
private:
    TreeNode <T> *root{nullptr};
    vector<TreeNode < T> *> list{};
public:

    TreeNodeLink(std::initializer_list<int32_t> list_) : list(TreeNode<T>::numToTree(list_)) {}

    explicit TreeNodeLink(const vector<TreeNode < T> *>& list_): list (list_) {}

    explicit TreeNodeLink(TreeNode <T> *li) : root(li) {}

    virtual ~TreeNodeLink() {
        stack<const TreeNode<T> *> sta{{root}};
        while (!sta.empty()) {
            const TreeNode<T> *const head = sta.top();
            sta.pop();
            if (head == nullptr) { continue; }
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
            delete head;
        }
        for (const auto &ele: list) {
            delete ele;
        }
    }
};

}
#endif //CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP
