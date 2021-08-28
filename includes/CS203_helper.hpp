/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:48:30
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 * @LastEditTime: 2021-01-03 21:45:55
 */
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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CS203_HELPER_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_CS203_HELPER_HPP
static constexpr double eps{0.00000001};
static constexpr double neps{-eps};

constexpr inline int32_t sign(int32_t x) {
    return ((x > 0) - (x < 0));
}

constexpr inline int32_t sign(double x) {
    return ((x < neps) ? -1 : (x > neps));
}

#endif //CS203_DSAA_TEMPLATE_INCLUDES_CS203_HELPER_HPP
