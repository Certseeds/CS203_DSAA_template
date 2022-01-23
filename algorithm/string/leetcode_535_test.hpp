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
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>
#include <unordered_map>

namespace leetcode_535 {

using std::string;
using std::unordered_map;

class base {
public:
    ~base() = default;

    virtual string encode(string longUrl) = 0;

    virtual string decode(string shortUrl) = 0;

    void ensure(const string &input) {
        CHECK(this->decode(this->encode(input)) == input);
    }
};

struct leetcode_535 {
    static base *getObject1();

};

TEST_CASE("1 [test_535]", "[test_535]") {
    static constexpr const char *const input{"you know the rules and so do I"};
    base *const pointer = leetcode_535::getObject1();
    CHECK(input == pointer->decode(pointer->encode(input)));
    pointer->ensure(input);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_HPP