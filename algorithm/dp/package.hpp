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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace zero_one_package {
using std::vector;

struct something final {
    something(int64_t cost, int64_t money) : cost(cost), money(money) {};
    int64_t cost, money;
};

enum class allow_unfull : bool {
    ALLOW = true, // 必须放满
    UN_ALLOW = false // 不必须放满
};

struct Package final : private nonCopyMoveAble {
private:
    const vector<something> things;
    const int64_t full;
public:
    Package(const vector<something> &things, int64_t maxV) : things(things), full(maxV) {}

    template<allow_unfull T>
    int64_t solve();

    template<allow_unfull T>
    int64_t solveSaveSpace();

    template<allow_unfull T>
    int64_t solveOneLine();
};
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP
