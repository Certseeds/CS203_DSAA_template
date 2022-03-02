// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_763 {
using std::vector;
using std::string;

struct leetcode_763 {
    static vector<int32_t> partitionLabels(const string &S);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_763]", "[test_763]") {
    static constexpr const char *const input{"ababcbacadefegdehijhklij"};
    const vector<int32_t> output{9, 7, 8};
    CHECK_THAT(output, Equals(leetcode_763::partitionLabels(input)));
}

TEST_CASE("2 [test_763]", "[test_763]") {
    static constexpr const char *const input{"eccbbbbdec"};
    const vector<int32_t> output{10};
    CHECK_THAT(output, Equals(leetcode_763::partitionLabels(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP
