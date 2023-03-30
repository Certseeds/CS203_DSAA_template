// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划


#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_97 {
using std::string;

struct leetcode_97 final {
    static bool isInterleave(const string &s1, const string &s2, const string &s3);
};

TEST_CASE("1 [test_97]", "[test_97]") {
    static constexpr const char *const s1{"aabcc"}, *const s2{"dbbca"}, *const s3{"aadbbcbcac"};
    CHECK(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("2 [test_97]", "[test_97]") {
    static constexpr const char *const s1{"aabcc"}, *const s2{"dbbca"}, *const s3{"aadbbbaccc"};
    CHECK_FALSE(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("3 [test_97]", "[test_97]") {
    static constexpr const char *const s1{""}, *const s2{""}, *const s3{""};
    CHECK(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("4 [test_97]", "[test_97]") {
    static constexpr const char *const s1{
            "abababababababababababababababababababababababababababababababababababababababababababababababababbb"},
            *const s2{
            "babababababababababababababababababababababababababababababababababababababababababababababababaaaba"},
            *const s3{
            "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"};
    CHECK_FALSE(leetcode_97::isInterleave(s1, s2, s3));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
