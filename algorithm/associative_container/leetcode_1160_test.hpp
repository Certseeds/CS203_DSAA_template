// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1160 {
using std::vector;
using std::string;
using std::string_view;

struct leetcode_1160 {
    static int32_t countCharacters(const vector<string> &words, string_view chars);
};

TEST_CASE("test case 1 {test_1160}", "{test_1160}") {
    const vector<string> input{"aaa", "bbb", "ccc"};
    const string chars{"aabbbcccc"};
    CHECK(6 == leetcode_1160::countCharacters(input, chars));
}

TEST_CASE("test case 2 {test_1160}", "{test_1160}") {
    const vector<string> input{"cat", "bt", "hat", "tree"};
    const string chars{"atach"};
    CHECK(6 == leetcode_1160::countCharacters(input, chars));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP
