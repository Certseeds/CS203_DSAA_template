/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
public:
    vector<TreeNode < T> *> list{};

    TreeNodeLink(std::initializer_list<int32_t> list_) : list(TreeNode<T>::numToTree(list_)) {}

    explicit TreeNodeLink(vector<TreeNode<T> *> list_): list(std::move(list_)) {}


    explicit TreeNodeLink(TreeNode <T> *li) {
        list.push_back(li);
    }

    virtual ~TreeNodeLink() {
        for (auto &i: list) {
            stack<const TreeNode<T> *> sta;
            sta.push(i);
            while (!sta.empty()) {
                const TreeNode<T> *head = sta.top();
                sta.pop();
                if (head->right != nullptr) {
                    sta.push(head->right);
                }
                if (head->left != nullptr) {
                    sta.push(head->left);
                }
                delete head;
            }
        }
    }
};

}
#endif //CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP
