/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-06 22:40:40 
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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP
enum class RBTColor : bool {
    Black = false,
    Red = true
};

template<class T>
class RBTNode {
private:
    T key;
    RBTColor color;
    RBTNode *parent;
    RBTNode *left;
    RBTNode *right;
public:
    RBTNode(T value, RBTColor c, RBTNode *p = nullptr, RBTNode *l = nullptr, RBTNode *r = nullptr) :
            key(value), color(c), parent(p), left(l), right(r) {}

    static void rec_remove(RBTNode *node);

    RBTColor get_color();

    T get_key();

    RBTNode *get_left();

    RBTNode *get_right();

    RBTNode *get_parent();

    /* RBTNode* get_grandparent(RBTNode<T>* node);
     RBTNode* get_uncle(RBTNode<T>* node);*/
    RBTNode *get_grandparent();

    RBTNode *get_uncle();

    void set_color(RBTColor c);

    void set_key(T val);

    void set_left(RBTNode *l);

    void set_right(RBTNode *r);

    void set_partent(RBTNode *p);


};

template<class T>
void RBTNode<T>::rec_remove(RBTNode *node) {
    if (node == nullptr) {
        return;
    }
    rec_remove(node->left);
    rec_remove(node->right);
    delete node;
}

template<class T>
inline RBTColor RBTNode<T>::get_color() {
    return this->color;
}

template<class T>
inline T RBTNode<T>::get_key() {
    return this->key;
}

template<class T>
inline RBTNode<T> *RBTNode<T>::get_left() {
    return this->left;
}

template<class T>
inline RBTNode<T> *RBTNode<T>::get_right() {
    return this->right;
}

template<class T>
inline RBTNode<T> *RBTNode<T>::get_parent() {
    return this->parent;
}

template<class T>
inline RBTNode<T> *RBTNode<T>::get_grandparent() {
    if (this->parent == nullptr) {
        return nullptr;
    }
    return this->parent->parent;
}

template<class T>
inline RBTNode<T> *RBTNode<T>::get_uncle() {
    if (this->get_grandparent() == nullptr) {
        return nullptr;
    }
    if (this->parent == this->get_grandparent()->left) {
        return this->get_grandparent()->right;
    }
    return this->get_grandparent()->left;
}

template<class T>
inline void RBTNode<T>::set_color(RBTColor c) {
    this->color = c;
}

template<class T>
inline void RBTNode<T>::set_key(T val) {
    this - key = val;
}

template<class T>
inline void RBTNode<T>::set_left(RBTNode *l) {
    this->left = l;
}

template<class T>
inline void RBTNode<T>::set_right(RBTNode *r) {
    this->right = r;
}

template<class T>
inline void RBTNode<T>::set_partent(RBTNode *p) {
    this->parent = p;
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTNODE_HPP
