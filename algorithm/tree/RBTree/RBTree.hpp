/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-06 22:41:41
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020  nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP

#include "RBTNode.hpp"
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::initializer_list;

template<typename T>
class RBTree {
private:
    inline bool check_law2() {
        return nil == this->root ||
               this->root->isBlack();
    }

    inline bool check_law3() {
        if (nil == this->root) {
            return true;
        }
        stack<RBTNode_t *> sta;
        sta.push(this->root);
        while (!sta.empty()) {
            const auto node = sta.top();
            sta.pop();
            if (node->left == nullptr && node->right == nullptr && node->isRed()) {
                return false;
            }
            if (node->right != nil) {
                sta.push(node->right);
            }
            if (node->left != nil) {
                sta.push(node->left);
            }
        }
        return true;
    }

    inline bool check_law4() {
        if (this->root == nil) {
            return true;
        }
        stack<RBTNode_t *> sta;
        sta.push(this->root);
        while (!sta.empty()) {
            const auto node = sta.top();
            sta.pop();
            if (node->isRed()) {
                if (node->left != nil && node->left->isRed()) {
                    return false;
                }
                if (node->right != nil && node->right->isRed()) {
                    return false;
                }
            }
            if (node->right != nil) {
                sta.push(node->right);
            }
            if (node->left != nil) {
                sta.push(node->left);
            }
        }
        return true;
    }

public:
    using RBTNode_t = RBTNode<T>;
    static constexpr RBTNode_t nilObject{0x11451419, RBTColor::Black, nullptr, nullptr, nullptr};
    static constexpr auto *nil = const_cast<RBTNode_t *>(&nilObject);
    RBTNode_t *root{nil};
    size_t size{0};

    RBTree() = default;

    RBTree(initializer_list<T> list) {
        this->insert(list);
    }

    ~RBTree() {
        if (this->root != nil) {
            stack<RBTNode_t *> sta;
            sta.push(this->root);
            while (!sta.empty()) {
                const auto node = sta.top();
                sta.pop();
                if (node->right != nil) {
                    sta.push(node->right);
                }
                if (node->left != nil) {
                    sta.push(node->left);
                }
                delete node;
            }
        }
    }

    void check() {
        if (!this->check_law2()) {
            std::cout << " law 2" << std::endl;
        }
        if (!this->check_law3()) {
            std::cout << " law 3" << std::endl;
        }
        if (!this->check_law4()) {
            std::cout << " law 4" << std::endl;
        }
    }

    void pre_order();

    void in_order();

    void pos_order();

    void insert(T key);

    void insert(std::initializer_list<T> key) {
        for (const auto &item : key) {
            RBTree<T>::insert(item);
        }
    }

    void insert_case1(RBTNode_t *node);

    void insert_case2(RBTNode_t *node);

    void insert_case3(RBTNode_t *node);

    void insert_case4(RBTNode_t *node);

    void insert_case5(RBTNode_t *node);

    void rorate_left(RBTNode_t *node);

    void rorate_right(RBTNode_t *node);

    RBTNode_t *rec_search(T key);

    RBTNode_t *iter_search(T key);

};

template<typename T>
void RBTree<T>::insert(T key) {
    auto *const node = new RBTNode_t(key, RBTColor::Red, nil, nil, nil);
    RBTNode_t *temp = root;
    while (temp != nil) {
        if (temp->key > key) {
            if (temp->left == nil) {
                temp->set_left(node);
                node->set_partent(temp);
                ++size;
                break;
            }
            temp = temp->left;
        } else if (temp->key < key) {
            if (temp->right == nil) {
                temp->set_right(node);
                node->set_partent(temp);
                ++size;
                break;
            }
            temp = temp->right;
        }
    }
    insert_case1(node);
}

template<typename T>
void RBTree<T>::insert_case1(RBTNode_t *node) {
    if (node->parent == nil) {
        this->root = node;
        node->set_black();
        ++size;
        return;
    }
    insert_case2(node);
}

template<typename T>
void RBTree<T>::insert_case2(RBTNode_t *node) {
    assert(node->parent != nil);
    if (node->parent->isBlack()) {
        return;
    }
    insert_case3(node);
}

template<typename T>
void RBTree<T>::insert_case3(RBTNode_t *node) {
    auto *const parent = node->parent;
    auto *const uncle = node->get_uncle();
    if (parent->isRed() && uncle != nil && uncle->isRed()) {
        auto *const p_parent = node->get_grandparent();
        // because parent is Red, so, parent can not be root( which must be Black)
        // so, it have p_parent node and no not need check
        parent->set_black();
        uncle->set_black();
        p_parent->set_red();
        if (p_parent->parent == nil) {
            --size;
        }
        insert_case1(p_parent);
        return;
    }
    insert_case4(node);
}

template<typename T>
void RBTree<T>::insert_case4(RBTNode_t *node) {
    auto *const parent = node->parent;
    auto *const uncle = node->get_uncle();
    //cout << "insert 4" << endl;
    if (parent->isRed() && (nil == uncle || uncle->isBlack())) {
        auto *const p_parent = node->get_grandparent();
        if (node == parent->right && parent == p_parent->left) {
            rorate_left(node);
            node = node->left;
        } else if (node == parent->left && parent == p_parent->right) {
            rorate_right(node);
            node = node->right;
        }
    }
    insert_case5(node);
}

template<typename T>
void RBTree<T>::insert_case5(RBTNode_t *node) {
    //cout << "insert 5" << endl;
    auto *const parent = node->parent;
    auto *const p_parent = node->get_grandparent();
    parent->set_black();
    p_parent->set_red();
    if (node == parent->left && p_parent->left == parent) {
        rorate_right(node->parent);
    } else if (node == parent->right && parent == p_parent->right) {
        rorate_left(node->parent);
    }
}

template<typename T>
void RBTree<T>::rorate_left(RBTNode_t *node) {
    RBTNode_t *const p_parent = node->get_grandparent();
    RBTNode_t *const parent = node->parent;
    if (p_parent != nil) {
        if (p_parent->left == parent) {
            p_parent->set_left(node);
        } else {
            p_parent->set_right(node);
        }
    }
    if (node->left != nil) {
        node->left->set_partent(parent);
    }
    parent->set_right(node->left);
    parent->set_partent(node);
    node->set_partent(p_parent);
    node->set_left(parent);
    if (node->parent == nil) {
        this->root = node;
    }
}

template<typename T>
void RBTree<T>::rorate_right(RBTNode_t *node) {
    auto *const p_parent = node->get_grandparent();
    auto *const parent = node->parent;
    if (p_parent != nil) {
        if (p_parent->left == parent) {
            p_parent->set_left(node);
        } else {
            p_parent->set_right(node);
        }
    }
    if (node->right != nil) {
        node->right->set_partent(parent);
    }
    parent->set_left(node->right);
    parent->set_partent(node);
    node->set_partent(p_parent);
    node->set_right(parent);
    if (node->parent == nil) {
        this->root = node;
    }
}

static const auto print = [](auto p) {
    int distance = p.first;
    const auto *node = p.second;
    std::cout << std::string(distance, ' ');
    std::cout << (node->isRed() ? 'R' : 'B') << ':';
    std::cout << node->key << '\n';
};
static constexpr const int32_t plusNumber = 2;

template<typename T>
void RBTree<T>::pre_order() {
    if (this->root == nil) {
        return;
    }
    stack<std::pair<int, RBTNode_t *>> sta;
    sta.push(std::make_pair(0, this->root));
    while (!sta.empty()) {
        const auto head = sta.top();
        const auto&[distance, node] = head;
        sta.pop();
        print(head);
        if (node->right != nil) {
            sta.push(std::make_pair(distance + plusNumber, node->right));
        }
        if (node->left != nil) {
            sta.push(std::make_pair(distance + plusNumber, node->left));
        }
    }
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP
