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

using std::cout;
using std::endl;
using std::initializer_list;

template<class T>
class RBTree {
private:

public:
    RBTNode<T> *root;

    RBTree();

    ~RBTree();

    void pre_order();

    void in_order();

    void pos_order();

    void insert(T key);

    void insert(std::initializer_list<T> key);

    void insert_1(RBTNode<T> *node);

    void insert_2(RBTNode<T> *node);

    void insert_3(RBTNode<T> *node);

    void insert_4(RBTNode<T> *node);

    void insert_5(RBTNode<T> *node);

    void rorate_left(RBTNode<T> *node);

    void rorate_right(RBTNode<T> *node);

    RBTNode<T> *rec_search(T key);

    RBTNode<T> *iter_search(T key);
};

template<class T>
RBTree<T>::RBTree() {
    this->root = nullptr;
}

template<class T>
RBTree<T>::~RBTree() {
    RBTNode<T>::rec_remove(this->root);
}

template<class T>
void RBTree<T>::insert(std::initializer_list<T> key) {
    for (const auto &item : key) {
        RBTree<T>::insert(item);
    }
}

template<class T>
void RBTree<T>::insert(T key) {
    //cout << "insert " << endl;
    auto *node = new RBTNode<T>(key, RBTColor::Red, nullptr, nullptr, nullptr);
    RBTNode<T> *temp = root;
    while (temp != nullptr) {
        if (temp->get_key() > key) {
            if (temp->get_left() == nullptr) {
                temp->set_left(node);
                node->set_partent(temp);
                temp = temp->get_left();
                break;
            }
            temp = temp->get_left();
        } else if (temp->get_key() < key) {
            if (temp->get_right() == nullptr) {
                temp->set_right(node);
                node->set_partent(temp);
                temp = temp->get_right();
                break;
            }
            temp = temp->get_right();
        }
    }
    insert_1(node);
}

template<class T>
void RBTree<T>::insert_1(RBTNode<T> *node) {
    if (node->get_parent() == nullptr) {
        this->root = node;
        node->set_color(RBTColor::Black);
        return;
    }
    insert_2(node);
}

template<class T>
void RBTree<T>::insert_2(RBTNode<T> *node) {
    if (node->get_parent()->get_color() == RBTColor::Black) {
        return;
    }
    insert_3(node);
}

template<class T>
void RBTree<T>::insert_3(RBTNode<T> *node) {
    //cout << "insert 3" << endl;
    if ((node->get_parent()->get_color() == RBTColor::Red) &&
        (node->get_uncle() != nullptr &&
         node->get_uncle()->get_color() == RBTColor::Red)) {
        node->get_parent()->set_color(RBTColor::Black);
        node->get_uncle()->set_color(RBTColor::Black);
        node->get_grandparent()->set_color(RBTColor::Red);
        RBTree<T>::insert_1(node->get_grandparent());
        return;
    }
    insert_4(node);
}

template<class T>
void RBTree<T>::insert_4(RBTNode<T> *node) {
    //cout << "insert 4" << endl;
    if ((node->get_parent()->get_color() == RBTColor::Red) &&
        (node->get_uncle() == nullptr ||
         node->get_uncle()->get_color() == RBTColor::Black)) {
        if (node == node->get_parent()->get_left() &&
            node->get_parent() == node->get_grandparent()->get_right()) {
            rorate_right(node);
            node = node->get_right();
        } else if (node == node->get_parent()->get_right() &&
                   node->get_parent() == node->get_grandparent()->get_left()) {
            rorate_left(node);
            node = node->get_left();
        }
    }
    insert_5(node);
}

template<class T>
void RBTree<T>::insert_5(RBTNode<T> *node) {
    //cout << "insert 5" << endl;
    node->get_parent()->set_color(RBTColor::Black);
    node->get_grandparent()->set_color(RBTColor::Red);
    if (node->get_parent()->get_left() == node &&
        node->get_grandparent()->get_left() == node->get_parent()) {
        rorate_right(node->get_parent());
    } else {
        rorate_left(node->get_parent());
    }
}

template<class T>
void RBTree<T>::rorate_left(RBTNode<T> *node) {
    RBTNode<T> *gp = node->get_grandparent();
    RBTNode<T> *fa = node->get_parent();
    if (gp != nullptr) {
        if (gp->get_left() == fa) {
            gp->set_left(node);
        } else {
            gp->set_right(node);
        }
    }
    if (node->get_left() != nullptr) {
        node->get_left()->set_partent(fa);
    }
    fa->set_right(node->get_left());
    fa->set_partent(node);
    node->set_partent(gp);
    node->set_left(fa);
    if (node->get_parent() == nullptr) {
        this->root = node;
    }
    /*RBTNode<T>* temp = gp->get_parent();
    gp->set_partent(node->get_parent());
    node->get_parent()->set_partent(temp);
    gp->set_right(node);
    node->get_parent()->set_left(gp);
    node->set_partent(gp);*/
}

template<class T>
void RBTree<T>::rorate_right(RBTNode<T> *node) {
    RBTNode<T> *gp = node->get_grandparent();
    RBTNode<T> *fa = node->get_parent();
    if (gp != nullptr) {
        if (gp->get_left() == fa) {
            gp->set_left(node);
        } else {
            gp->set_right(node);
        }
    }
    if (node->get_right() != nullptr) {
        node->get_right()->set_partent(fa);
    }
    fa->set_left(node->get_right());
    fa->set_partent(node);
    node->set_partent(gp);
    node->set_right(fa);
    if (node->get_parent() == nullptr) {
        this->root = node;
    }
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP
