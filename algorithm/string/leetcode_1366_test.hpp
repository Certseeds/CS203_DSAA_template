// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1366_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1366_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1366 {
using std::string;

namespace leetcode_1366 {
string rankTeams(const vector<string> &votes);

}

TEST_CASE("1 [test_1366]", "[test_1366]") {
    const vector<string> input{"ABC", "ACB", "ABC", "ACB", "ACB"};
    const char *const result{"ACB"};
    CHECK(result == leetcode_1366::rankTeams(input));
}

TEST_CASE("2 [test_1366]", "[test_1366]") {
    const vector<string> input{"WXYZ", "XYZW"};
    const char *const result{"XWYZ"};
    CHECK(result == leetcode_1366::rankTeams(input));
}


TEST_CASE("3 [test_1366]", "[test_1366]") {
    const vector<string> input{"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    const char *const result{"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    CHECK(result == leetcode_1366::rankTeams(input));
}


TEST_CASE("4 [test_1366]", "[test_1366]") {
    const vector<string> input{"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    const char *const result{"ABC"};
    CHECK(result == leetcode_1366::rankTeams(input));
}


TEST_CASE("5 [test_1366]", "[test_1366]") {
    const vector<string> input{"M", "M", "M", "M"};
    const char *const result{"M"};
    CHECK(result == leetcode_1366::rankTeams(input));
}

TEST_CASE("6 [test_1366]", "[test_1366]") {
    const vector<string> input{ "FVSHJIEMNGYPTQOURLWCZKAX",
                                "AITFQORCEHPVJMXGKSLNZWUY",
                                "OTERVXFZUMHNIYSCQAWGPKJL",
                                "VMSERIJYLZNWCPQTOKFUHAXG",
                                "VNHOZWKQCEFYPSGLAMXJIUTR",
                                "ANPHQIJMXCWOSKTYGULFVERZ",
                                "RFYUXJEWCKQOMGATHZVILNSP",
                                "SCPYUMQJTVEXKRNLIOWGHAFZ",
                                "VIKTSJCEYQGLOMPZWAHFXURN",
                                "SVJICLXKHQZTFWNPYRGMEUAO",
                                "JRCTHYKIGSXPOZLUQAVNEWFM",
                                "NGMSWJITREHFZVQCUKXYAPOL",
                                "WUXJOQKGNSYLHEZAFIPMRCVT",
                                "PKYQIOLXFCRGHZNAMJVUTWES",
                                "FERSGNMJVZXWAYLIKCPUQHTO",
                                "HPLRIUQMTSGYJVAXWNOCZEKF",
                                "JUVWPTEGCOFYSKXNRMHQALIZ",
                                "MWPIAZCNSLEYRTHFKQXUOVGJ",
                                "EZXLUNFVCMORSIWKTYHJAQPG",
                                "HRQNLTKJFIEGMCSXAZPYOVUW",
                                "LOHXVYGWRIJMCPSQENUAKTZF",
                                "XKUTWPRGHOAQFLVYMJSNEIZC",
                                "WTCRQMVKPHOSLGAXZUEFYNJI"};
    const char *const result{"VWFHSJARNPEMOXLTUKICZGYQ"};
    CHECK(result == leetcode_1366::rankTeams(input));
}




}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1366_TEST_HPP
