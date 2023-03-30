// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_1078 {
using std::vector;

struct leetcode_1078 {
    static vector<string> findOcurrences(const string &text, const string &first, const string &second);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1078}", "{test_1078}") {
    static constexpr const char *const text{"how are you indian mi fans do you like mi four i"};
    static constexpr const char *const fst{"mi"};
    static constexpr const char *const snd{"fans"};
    const vector<string> result{"do"};
    CHECK_THAT(result, Equals(leetcode_1078::findOcurrences(text, fst, snd)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP
