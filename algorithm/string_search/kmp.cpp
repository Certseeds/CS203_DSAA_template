/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-04-02 09:50:56
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2021  nanos

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
#include "string_search.hpp"
#include <string>
#include <vector>

using std::vector;
using std::string;

int strStr_kmp(const string &h, const string &n);

vector<int32_t> get_next(const string &h);

int strStr(const std::string &h, const std::string &n) {
    return strStr_kmp(h, n);
}

int strStr_kmp(const string &h, const string &n) {
    if (n.empty()) {
        return 0;
    } else if (h.size() < n.size()) {
        return -1;
    }
    int32_t x{0}, y{0};
    int32_t hsize{static_cast<int32_t>(h.size())}, nsize{static_cast<int32_t>(n.size())};
    vector<int32_t> next = get_next(n);
    while ((x < hsize) && (y < nsize)) {
        if (y == -1 || h[x] == n[y]) {
            x++;
            y++;
        } else {
            y = next[y];
        }
    }
    if (y == nsize) {
        return x - y;
    }
    return -1;
}

vector<int32_t> get_next(const string &h) {
    vector<int32_t> will_return(h.size(), -1);
    int64_t x = -1;
    size_t y = 0;
    while (y < h.size() - 1) {
        if (x == -1 || h[x] == h[y]) {
            x++;
            y++;
            will_return[y] = x;
        } else {
            x = will_return[x];
        }
    }
    return will_return;
}
