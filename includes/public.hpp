/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:44:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-30 11:27:06
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020  nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_PUBLIC_H
#define CS203_DSAA_TEMPLATE_INCLUDES_PUBLIC_H

#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include "CS203_helper.hpp"
#include "CS203_timer.hpp"
#include "CS203_redirect.hpp"

using std::ios;
using std::cin;
using std::cout;
CS203_timer timer{};
static int faster_streams = []() {
    srand(time(0));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();

bool compareFiles(std::string p1, std::string p2) {
    p1 = CS203_redirect::file_paths + p1;
    p2 = CS203_redirect::file_paths + p2;
    // get from https://stackoverflow.com/questions/6163611/compare-two-files
    std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);
    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }
    if (f1.tellg() != f2.tellg()) {
        std::cout << p1 << " not match " << p2 << '\n';
        std::cout << f1.tellg() << " " << f2.tellg() << '\n';
        return false; //size mismatch
    }
    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

#endif //CS203_DSAA_TEMPLATE_INCLUDES_PUBLIC_H
