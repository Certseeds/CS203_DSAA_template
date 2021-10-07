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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP

#include <TreeNodeTemp.hpp>

namespace RED_BLACK_TREE_NODE {
using TREE_NODE_TEMP::TreeNodeTemp;
enum class RBTColor : bool {
    Black = false,
    Red = true
};

template<typename T>
class RBTNode : public TreeNodeTemp<T, RBTNode> {
private:
    using base = TreeNodeTemp<T, RBTNode>;
public:
    RBTNode *parent{nullptr};
    RBTColor color{RBTColor::Black};

    constexpr explicit RBTNode(T value, RBTNode *l = nullptr, RBTNode *r = nullptr, RBTNode *p = nullptr,
                      RBTColor c = RBTColor::Red) : base(value, l, r), parent(p), color(c) {}

    ~RBTNode() override = default;

    inline RBTNode *get_grandparent() const {
        if (this->parent == nullptr) {
            return nullptr;
        }
        return this->parent->parent;
    }

    inline RBTNode *get_uncle() const {
        RBTNode *const grand_parent = this->get_grandparent();
        if (nullptr == grand_parent) {
            return nullptr;
        }
        if (this->parent == grand_parent->left) {
            return grand_parent->right;
        }
        return grand_parent->left;
    }

    inline RBTNode *get_brother() const {
        RBTNode *const p_node = this->parent;
        if (nullptr == p_node) {
            return nullptr;
        }
        if (this == p_node->left) {
            return p_node->right;
        }
        return p_node->left;
    }

    inline void isLeaf() const {
        return this->left == nullptr && this->right == nullptr;
    }

    inline void set_black() {
        this->color = RBTColor::Black;
    }

    inline void set_red() {
        this->color = RBTColor::Red;
    }

    [[nodiscard]] inline bool isRed() const {
        return this->color == RBTColor::Red;
    }

    [[nodiscard]] inline bool isBlack() const {
        return this->color == RBTColor::Black;
    }

    inline void set_left(RBTNode *l) {
        this->left = l;
    }

    inline void set_right(RBTNode *r) {
        this->right = r;
    }

    inline void set_partent(RBTNode *p) {
        this->parent = p;
    }

    friend bool operator==(const RBTNode<T> &v, const RBTNode<T> &rbtNode) {
        return rbtNode == v;
    }

    bool operator==(const T &v) const {
        return this->val == v;
    }

    friend bool operator==(const T &v, const RBTNode<T> &rbtNode) {
        return rbtNode == v;
    }

    bool operator==(const std::tuple<T, T, T> &v) const {
        const auto&[key, left, right] = v;
        return key == this->val &&
               this->left != nullptr && left == *this->left &&
               this->right != nullptr && right == *this->right;
    }

};
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP
