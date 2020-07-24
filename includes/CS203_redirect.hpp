/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-25 01:56:19 
 * @LastEditors: nanoseeds
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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CS203_REDIRECT_H
#define CS203_DSAA_TEMPLATE_INCLUDES_CS203_REDIRECT_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class CS203_redirect {
private:
    std::streambuf *strmin_buf;
    std::streambuf *strmout_buf;
    std::ifstream file_in = std::ifstream();
    std::ofstream file_out = std::ofstream();
public:
    // default path1 is input and path2 is output
    explicit CS203_redirect(string path1, string path2) {
        this->strmin_buf = std::cin.rdbuf();
        this->strmout_buf = std::cout.rdbuf();
        file_in.open(path1);
        std::cin.rdbuf(file_in.rdbuf());
        if (!path2.empty()) {
            file_out.open(path2);
            std::cout.rdbuf(file_out.rdbuf());
        }
    }

    CS203_redirect(const CS203_redirect &redirect) = delete;

    CS203_redirect(CS203_redirect &&redirect) = delete;

    CS203_redirect &operator=(const CS203_redirect &redirect) = delete;

    CS203_redirect &operator=(CS203_redirect &&mat) = delete;

    ~CS203_redirect() {
        std::cin.rdbuf(strmin_buf);
        std::cout.rdbuf(strmout_buf);
        std::cout.flush();
    }

};

#endif //CS203_DSAA_TEMPLATE_INCLUDES_CS203_REDIRECT_H
