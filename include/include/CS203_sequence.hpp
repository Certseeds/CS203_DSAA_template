/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template

 * @Author: nanoseeds
 * @Date: 2020/9/19 21:42:36
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021 nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CS203_SEQUENCE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_CS203_SEQUENCE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class CS203_sequence {
private:
    std::string prefix_of_file_name{""};
    std::string postfix_of_testout{"test.out"};
    std::string postfix_of_datain{"data.in"};
    std::string postfix_of_dataout{"data.out"};
    int32_t begin{0};
    int32_t end{0};
    int32_t max_length{-1};
public:

    // default path1 is input and path2 is output
    explicit CS203_sequence(int32_t begin, int32_t end, int32_t max_length = -1) : begin(begin), end(end),
                                                                                   max_length(max_length) {
    }

    CS203_sequence(const CS203_sequence &redirect) = delete;

    CS203_sequence(CS203_sequence &&redirect) = delete;

    CS203_sequence &operator=(const CS203_sequence &redirect) = delete;

    CS203_sequence &operator=(CS203_sequence &&mat) = delete;

    void set_prefix_of_filename(const string &prefixOfFileName) {
        prefix_of_file_name = prefixOfFileName;
    }

    void set_postfix_of_testout(const string &postfixOfTestout) {
        postfix_of_testout = postfixOfTestout;
    }

    void set_postfix_of_datain(string postfixOfDatain) {
        postfix_of_datain = std::move(postfixOfDatain);
    }

    void set_postfix_of_dataout(const string &postfixOfDataout) {
        postfix_of_dataout = postfixOfDataout;
    }

    /*
     *     [begin,end]
    */
    vector<string> get_sequence() const {
        vector<string> will_return{};
        for (int32_t i = begin; i <= end; ++i) {
            will_return.push_back(std::to_string(i));
        }
        return will_return;
    }

    // [begin,end]
    // 默认max_length = -1,即使用end的长度
    // 若max_length != -1,即传入参数,则使用std::max(end长度,max_length)
    vector<string> get_same_length_sequence() const {
        int max_lengths = std::max(max_length, get_length(end));
        vector<string> will_return = get_sequence();
        for (auto &item: will_return) {
            if (static_cast<int32_t>(item.length()) < max_lengths) {
                item.insert(std::begin(item), max_lengths - item.length(), '0');
            }
        }
        return will_return;
    }

    inline static int32_t get_length(int32_t value) {
        int32_t length = 0;
        while (value > 0) {
            length++;
            value /= 10;
        }
        return length;
    }

    using files_type = vector<std::tuple<std::string, std::string, std::string>>;

    files_type get_files(bool same_length) const {
        vector<string> sequence = same_length ? get_same_length_sequence() : get_sequence();
        files_type will_return;
        for (const auto &item: sequence) {
            string datain = prefix_of_file_name + item + "." + postfix_of_datain;
            string dataout = prefix_of_file_name + item + "." + postfix_of_dataout;
            string testout = prefix_of_file_name + item + "." + postfix_of_testout;
            will_return.push_back(std::make_tuple(datain, dataout, testout));
        }
        return will_return;
    }
};

#endif //CS203_DSAA_TEMPLATE_INCLUDES_CS203_SEQUENCE_HPP
