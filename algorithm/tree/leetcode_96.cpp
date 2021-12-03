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
#include "leetcode_96_test.hpp"

namespace leetcode_96 {

int32_t leetcode_96::numTrees(int32_t n) {
    static unordered_map<int32_t, int32_t> umap;
    if (n <= 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }
    if (umap.count(n) != 0) {
        return umap[n];
    }
    int32_t will_return{0};
    for (int32_t i{0}; i < n; i++) {
        const auto fir{numTrees(i)};
        umap[i] = fir;
        const auto sec{numTrees(n - i - 1)};
        umap[n - i - 1] = sec;
        will_return += (fir * sec);
    }
    // 这题需要用DP,关键在于 [m,m+k]和[n,n+k] 这两个范围的节点形成的子树完全同构, 数量是一致的,可以复用
    return will_return;
}


}