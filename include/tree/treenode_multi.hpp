/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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
