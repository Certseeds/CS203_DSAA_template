// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day17
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_516_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_516_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <string>

namespace leetcode_516 {
using std::string;

namespace leetcode_516 {
// 最长回文子序列
int32_t longestPalindromeSubseq(const string &s);
}


TEST_CASE("1 [test_516]", "[test_516]") {
    static constexpr const char *const input{"bbbab"};
    static constexpr const auto result{4};
    CHECK(result == leetcode_516::longestPalindromeSubseq(input));
}

TEST_CASE("2 [test_516]", "[test_516]") {
    static constexpr const char *const input{"cddb"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_516::longestPalindromeSubseq(input));
}

TEST_CASE("4 [test_516]", "[test_516]") {
    static constexpr const char *const input{"aa"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_516::longestPalindromeSubseq(input));
}

TEST_CASE("3 [test_516]", "[test_516]") {
    static constexpr const char *const input{
            "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"
    };
    static constexpr const auto result{159};
    CHECK(result == leetcode_516::longestPalindromeSubseq(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_516_TEST_CPP
