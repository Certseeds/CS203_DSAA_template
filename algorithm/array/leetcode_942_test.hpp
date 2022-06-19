// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_942_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_942_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_942 {
using std::vector;
using std::string;

struct leetcode_942 {
    static vector<int> diStringMatch(const string &str);
};

static void check(const string &str, const vector<int32_t> &vec) {
    const auto str_size{str.size()}, vec_size{vec.size()};
    CHECK(str_size + 1 == vec_size);
    for (size_t i{0}; i < str_size; ++i) {
        CHECK((str[i] == 'I' || str[i] == 'D'));
        if (str[i] == 'I') {
            CHECK(vec[i] < vec[i + 1]);
        } else {
            CHECK(vec[i] > vec[i + 1]);
        }
    }
}

TEST_CASE("test case 1 {test_942}", "{test_942}") {
    static constexpr const char *const str{"IDID"};
    check(str, leetcode_942::diStringMatch(str));
}

TEST_CASE("test case 2 {test_942}", "{test_942}") {
    static constexpr const char *const str{"III"};
    check(str, leetcode_942::diStringMatch(str));
}

TEST_CASE("test case 3 {test_942}", "{test_942}") {
    static constexpr const char *const str{"DDI"};
    check(str, leetcode_942::diStringMatch(str));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_942_TEST_HPP
