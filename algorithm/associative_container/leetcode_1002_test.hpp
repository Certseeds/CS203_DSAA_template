// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag xor
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <array>

namespace leetcode_1002 {
using std::array;
using std::string;
using std::vector;

struct leetcode_1002 {
    static vector<string> commonChars(const vector<string> &words);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 3> arr{
            "bella", "label", "roller"
    };
    static constexpr const std::array<const char *const, 3> result{
            "e", "l", "l"
    };
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(leetcode_1002::commonChars({arr.cbegin(), arr.cend()}))
    );

}

TEST_CASE("test case 2 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 3> arr{
            "cool", "lock", "cook"
    };
    static constexpr const std::array<const char *const, 2> result{
            "c", "o"
    };
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(leetcode_1002::commonChars({arr.cbegin(), arr.cend()}))
    );

}

TEST_CASE("test case 3 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 8> arr{
            "acabcddd", "bcbdbcbd", "baddbadb", "cbdddcac", "aacbcccd", "ccccddda", "cababaab", "addcaccd"
    };
    static constexpr const std::array<const char *const, 0> result{};
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(leetcode_1002::commonChars({arr.cbegin(), arr.cend()}))
    );

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP
