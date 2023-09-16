// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1371 {
using std::vector;

namespace leetcode_1371 {
int32_t findTheLongestSubstring(const std::string &s);
}

TEST_CASE("test case 1-1 {test_1371}", "{test_1371}") {
    constexpr const char*const input{"leetcodeisgreat"};
    constexpr const auto output{5};
    CHECK(output == leetcode_1371::findTheLongestSubstring(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP
