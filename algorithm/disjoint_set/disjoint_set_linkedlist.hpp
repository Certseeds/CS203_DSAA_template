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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP

#include <vector>
#include <class_helper/nonable.hpp>

namespace disjoint_set {
namespace linkedlist {
using std::vector;

template<typename T>
class base {
protected:
    struct node_base {
        const size_t v{};

        explicit node_base(size_t v) : v(v) {}
    };

public:
    static T* make_set(size_t x) { return T::make_set(x); }

    static T *unio(T *fst, T *snd) { return T::unio(fst, snd); }

    static node_base *find_set(const node_base &x) { return T::find_set(x); }
};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP
