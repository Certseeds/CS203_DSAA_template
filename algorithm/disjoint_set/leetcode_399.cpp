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
#include "leetcode_399_test.hpp"

namespace disjoint_set_weight {
// 节点之间是一张 有向无环图
class disjoint_set final {
private:
    std::vector<size_t> fa; // 记录father
    std::vector<double_t> weights; // 记录子节点
public:
    explicit disjoint_set(size_t size) : fa(vector<size_t>(size + 1, -1)),
                                         weights(vector<double_t>(size + 1, static_cast<double_t>(1.0f))) {
        // 0号元素弃用
        // from 1 to ${size}
        // value is 1 to ${size}
        std::iota(fa.begin(), fa.end(), 0);
    }

    size_t find(size_t x) {
        if (this->fa[x] != x) {
            const auto faorigin{fa[x]};
            this->fa[x] = find(faorigin);
            weights[x] *= weights[faorigin];
        }
        return this->fa[x];
    }

    void merge(size_t x, size_t y, double value) {
        const auto xfa = find(x),
                yfa = find(y);
        if (xfa == yfa) {
            return;
        }
        fa[xfa] = yfa;
        weights[xfa] = weights[y] * value / weights[x];
        // 此处 weights[y] => y到yfa的weight
        // value => x到y的weight
        // weights[x] => x到x fa的weight
        // 由于不能出现矛盾, `x => xfa => yfa` === `x => y => yfa`
        // 因此可求得 x的father的weights
    }

    double findWeight(size_t x) {
        this->find(x);
        return weights[x];
    }
};
}

namespace leetcode_399 {
using disjoint_set_weight::disjoint_set;
using std::unordered_map;

vector<double> leetcode_399::calcEquation(const vector<vector<string>> &equations, const vector<double> &values,
                                          const vector<vector<string>> &queries) {
    unordered_map<string, size_t> str_to_num{};
    for (const auto &pair: equations) {
        for (const auto &str: pair) {
            if (str_to_num.count(str) == 0) {
                str_to_num.emplace(str, str_to_num.size() + 1);
            }
        }
    }
    disjoint_set dset(str_to_num.size());
    for (size_t i{0}; i < equations.size(); i++) {
        const auto &pair = equations[i];
        const auto first{str_to_num[pair[0]]},
                second{str_to_num[pair[1]]};
        dset.merge(first, second, values[i]);
    }
    vector<double_t> results(queries.size(), -1);
    for (size_t i{0}; i < queries.size(); i++) {
        const auto &query{queries[i]};
        const auto &first{query[0]}, second{query[1]};
        if (str_to_num.count(first) == 0 || str_to_num.count(second) == 0) {
            continue;
        }
        const auto firstNum{str_to_num[first]},
                secondNum{str_to_num[second]};
        if (dset.find(firstNum) != dset.find(secondNum)) {
            continue;
        }
        if (firstNum == secondNum) {
            results[i] = 1.0f;
            continue;
        }
        auto multiOne{dset.findWeight(firstNum)},
                multiTwo{dset.findWeight(secondNum)};
        results[i] = multiOne / multiTwo;
    }

    return results;
}


}