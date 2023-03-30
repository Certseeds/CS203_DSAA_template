// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 剑指OfferII-I Day03
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_so_05 {

using std::string;

struct leetcode_so_05 {
    static string replaceSpace(const string &str);
};


TEST_CASE("1 [test_so_05]", "[test_so_05]") {
    static constexpr const char *const input{"We are happy."}, *const result{"We%20are%20happy."};
    CHECK(result == leetcode_so_05::replaceSpace(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP
