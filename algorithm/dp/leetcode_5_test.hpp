// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day17
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_5 {
namespace lcs_5 {

using std::string;
using std::vector;

namespace leetcode_5 {
string longestPalindrome(const string &s);
}

template<typename Type, size_t length>
constexpr size_t arr_length(const Type (&)[length]) {
    return length;
}

template<size_t length>
constexpr size_t arr_length(const char (&)[length]) {
    return length - 1;
}

TEST_CASE("1 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"babad"};
    static constexpr const char result[]{"bab"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
}

TEST_CASE("2 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cbbc"};
    static constexpr const char result[]{"cbbc"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

TEST_CASE("2_  [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cbbd"};
    static constexpr const char result[]{"bb"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

TEST_CASE("3 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cb"};
    static constexpr const char result[]{"c"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
}

TEST_CASE("4 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"c"};
    static constexpr const char result[]{"c"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}


TEST_CASE("5 [test_5]", "[test_5]") {
    static constexpr const auto *const input{""};
    static constexpr const char result[]{""};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

TEST_CASE("6 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"ac"};
    static constexpr const char result[]{"a"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

TEST_CASE("7 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"aaaaa"};
    static constexpr const char result[]{"aaaaa"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

TEST_CASE("8 [test_5]", "[test_5]") {
    static constexpr const auto *const input{
            "mozblnzrszxtdjmwvgeovtxoftpcsbnjryogrnibiiqfexljlfikfcxvrzrpfvugtdjrlkgvkmrqgeltifdehsewpdhpjpnuobmuozopmglnocqcozvratjpzrklexqdeuvvzfjkuknkkoynxptrgtzadmpfdkphfjhdulhzncoofmmrwqjxeyhodfavcgpjmohohuztezdxegqzbaaobzrqptuqsvwnfdneyccbkgkjafztytwuppvleukdqqzyeiltsvoqbxupbasiityganofxijucwzqgtdyxljociwwjdrnfnfbwyymmvbuvbrdnvcubzkohknbsneutrcukfiqqhfviqdsbtrldipenqifdcrenpuyaqvkparycksurhbtjppwhezbcgocamurdawimkzzkmiwadrumacogcbzehwppjtbhruskcyrapkvqayupnercdfiqnepidlrtbsdqivfhqqifkucrtuensbnkhokzbucvndrbvubvmmyywbfnfnrdjwwicojlxydtgqzwcujixfonagytiisabpuxbqovstlieyzqqdkuelvppuwtytzfajkgkbccyendfnwvsqutpqrzboaabzqgexdzetzuhohomjpgcvafdohyexjqwrmmfoocnzhludhjfhpkdfpmdaztgrtpxnyokknkukjfzvvuedqxelkrzpjtarvzocqconlgmpozoumbounpjphdpweshedfitlegqrmkvgklrjdtguvfprzrvxcfkifljlxefqiibinrgoyrjnbscptfoxtvoegvwmjdtxzsrznlbzom"};
    static constexpr const char result[]{
            "mozblnzrszxtdjmwvgeovtxoftpcsbnjryogrnibiiqfexljlfikfcxvrzrpfvugtdjrlkgvkmrqgeltifdehsewpdhpjpnuobmuozopmglnocqcozvratjpzrklexqdeuvvzfjkuknkkoynxptrgtzadmpfdkphfjhdulhzncoofmmrwqjxeyhodfavcgpjmohohuztezdxegqzbaaobzrqptuqsvwnfdneyccbkgkjafztytwuppvleukdqqzyeiltsvoqbxupbasiityganofxijucwzqgtdyxljociwwjdrnfnfbwyymmvbuvbrdnvcubzkohknbsneutrcukfiqqhfviqdsbtrldipenqifdcrenpuyaqvkparycksurhbtjppwhezbcgocamurdawimkzzkmiwadrumacogcbzehwppjtbhruskcyrapkvqayupnercdfiqnepidlrtbsdqivfhqqifkucrtuensbnkhokzbucvndrbvubvmmyywbfnfnrdjwwicojlxydtgqzwcujixfonagytiisabpuxbqovstlieyzqqdkuelvppuwtytzfajkgkbccyendfnwvsqutpqrzboaabzqgexdzetzuhohomjpgcvafdohyexjqwrmmfoocnzhludhjfhpkdfpmdaztgrtpxnyokknkukjfzvvuedqxelkrzpjtarvzocqconlgmpozoumbounpjphdpweshedfitlegqrmkvgklrjdtguvfprzrvxcfkifljlxefqiibinrgoyrjnbscptfoxtvoegvwmjdtxzsrznlbzom"};
    CHECK(arr_length(result) == leetcode_5::longestPalindrome(input).size());
    CHECK(result == leetcode_5::longestPalindrome(input));
}

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
