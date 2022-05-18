// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag array as hashmap
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_890 {
using std::vector;

struct leetcode_890 {
    static vector<string> findAndReplacePattern(const vector<string> &words, const string &pattern);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_890}", "{test_890}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    static constexpr const char *const pattern{"abb"};
    static constexpr const std::array<const char *const, 2> result{"mee", "aqq"};
    CHECK_THAT(
            (vector<string>{result.cbegin(), result.cend()}),
            Equals(leetcode_890::findAndReplacePattern({input.cbegin(), input.cend()}, pattern))
    );

}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP
