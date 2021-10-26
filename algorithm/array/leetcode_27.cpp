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
#include "leetcode_27_test.hpp"

namespace leetcode_27 {

int leetcode_27::removeElement(vector<int32_t> &vec, int32_t val) {
    vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
    return vec.size();
}

int leetcode_27::removeElement2(vector<int32_t> &vec, int32_t val) {
    const size_t vec_size{vec.size()};
    int32_t order{0};
    for(size_t begin{0};begin < vec_size;begin++) {
        if (vec[begin] != val) {
            vec[order] = vec[begin];
            order++;
        }
    }
    vec.resize(order);
    return order;
}
}