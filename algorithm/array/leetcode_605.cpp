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
#include "leetcode_605_test.hpp"

namespace leetcode_605 {

// 虽然是种花问题,但是也可以映射到其他问题上,比如一个很常见的问题......

bool leetcode_605::canPlaceFlowers(const vector<int32_t> &urinal_immutable, int32_t n) {
    vector<int32_t> urinal{urinal_immutable};
    const auto urinal_size{urinal.size()};
    if (n == 0) {
        return true;
    } else if ((urinal_size + 1) / 2 < static_cast<size_t>(n)) {
        return false;
    } else if (urinal_size == 1) {
        return urinal[0] != 1;
    } else if (urinal_size == 2) {
        return urinal[0] != 1 && urinal[1] != 1;
    }
    if (urinal[0] == 0 && urinal[1] == 0) {
        urinal[0] = 1;
        n--;
    }
    if (urinal[urinal_size - 1] == 0 && urinal[urinal_size - 2] == 0) {
        urinal[urinal_size - 1] = 1;
        n--;
    }
    for (size_t i{1}, temp{1}; n > 0; temp = i) {
        for (; i < urinal_size; i++) {
            if (urinal[i - 1] == 0 && urinal[i] == 0 && urinal[i + 1] == 0) {
                urinal[i] = 1;
                i += 2;
                n--;
                break;
            }
        }
        if (temp == i) {
            return false;
        }
    }
    return true;
}

}
