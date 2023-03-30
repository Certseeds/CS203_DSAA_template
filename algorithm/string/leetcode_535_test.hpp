// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_535 {

using std::string;

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP
