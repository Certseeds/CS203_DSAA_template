/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//@Tag DP
//@Tag 动态规划
//@Tag
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace lcs_5 {
using std::string;
using std::vector;

struct leetcode_5 {
    static string longestPalindrome(const string &s);
};
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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
