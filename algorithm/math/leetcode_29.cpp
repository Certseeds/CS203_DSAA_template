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
#include "leetcode_29_test.hpp"

namespace leetcode_29 {

int leetcode_29::divide(int32_t dividend, int32_t divisor) {
    if (dividend == divisor) {
        return 1;
    } else if (divisor == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (divisor == 1) {
        return dividend;
    }
    int32_t will_return{0}, signs{1};
    if (dividend == std::numeric_limits<int32_t>::min()) {
        if (divisor == -1) {
            return std::numeric_limits<int32_t>::max();
        }
        will_return += 1;
        // pay attention to the `sign` function
        dividend += sign(divisor) * divisor;
    }
    signs *= sign(dividend) * sign(divisor);
    dividend *= sign(dividend);
    divisor *= sign(divisor);
    while (dividend >= divisor) {
        short temp = 0;
        //cout << dividend << " " << divisor << endl;
        while (dividend >= divisor) {
            //cout << dividend << " " << temp << " " << divisor << endl;
            if ((dividend >> 1) < (divisor << temp)) {
                dividend -= (divisor << temp);
                will_return += (1 << temp);
                break;
            }
            temp++;
        }
    }
    return will_return * signs;
}

}