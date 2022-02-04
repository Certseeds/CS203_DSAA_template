/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP

#include <vector>
#include <class_helper/nonable.hpp>

namespace disjoint_set_base {
using std::vector;

class DisjointSetBase : private nonCopyMoveAble {
protected:
    std::vector<size_t> fa; // 记录father
    std::vector<size_t> points; // 记录子节点
public:
    explicit DisjointSetBase(size_t size) : fa(vector<size_t>(size + 1, -1)) {};

    virtual size_t find(size_t x) = 0;

    virtual void merge(size_t x, size_t y) = 0;

    virtual void mergeHeur(size_t x, size_t y) = 0;

};
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_BASE_HPP
