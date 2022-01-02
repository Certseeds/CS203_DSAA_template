/*
MIT License

CS203_DSAA_template

Copyright (C) 2021 nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_TEMP_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_TEMP_HPP
#include <class_helper/nonable.hpp>
namespace TREE_NODE_TEMP {
template<typename T, template<typename> typename CLASS>
struct TreeNodeTemp : private nonCopyMoveAble {
public:
    T val;
    CLASS<T> *left, *right;

    virtual ~TreeNodeTemp() {
        this->val = static_cast<T>(0);
        this->left = nullptr;
        this->right = nullptr;
    }


private:
    explicit TreeNodeTemp(T x = static_cast<T>(0)) : TreeNodeTemp<T, CLASS>(x, nullptr, nullptr) {};

    TreeNodeTemp(T x, CLASS<T> *le, CLASS<T> *rig) : val(x), left(le), right(rig) {};

    friend CLASS<T>;
};
}
#endif //CS203_DSAA_TEMPLATE_INCLUDE_TREE_TREENODE_TEMP_HPP
