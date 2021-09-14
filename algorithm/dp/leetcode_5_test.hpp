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

#include <vector>
#include <string>
#include <catch_main.hpp>

namespace lcs_5 {
using std::string;
using std::vector;

struct leetcode_5 {
    static string longestPalindrome(const string &s);
};

TEST_CASE("1 [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("babad").size() == 3);
}

TEST_CASE("2 [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("cbbc").size() == 4);
}

TEST_CASE("2_  [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("cbbd").size() == 2);
}

TEST_CASE("3 [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("cb").size() == 1);
}

TEST_CASE("4 [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("c").size() == 1);
}

TEST_CASE("5 [test 5]", "[test 5]") {
    CHECK(leetcode_5::longestPalindrome("").empty());
}

TEST_CASE("6 [test 5]", "[test 5]") {
    const string str = "ac";
    CHECK(leetcode_5::longestPalindrome(str).size() == 1);
    CHECK(leetcode_5::longestPalindrome(str) == "a");
}

TEST_CASE("7 [test 5]", "[test 5]") {
    const string str = "aaaaa";
    CHECK(leetcode_5::longestPalindrome(str).size() == 5);
    CHECK(leetcode_5::longestPalindrome(str) == str);
}

TEST_CASE("8 [test 5]", "[test 5]") {
    const string str = "mozblnzrszxtdjmwvgeovtxoftpcsbnjryogrnibiiqfexljlfikfcxvrzrpfvugtdjrlkgvkmrqgeltifdehsewpdhpjpnuobmuozopmglnocqcozvratjpzrklexqdeuvvzfjkuknkkoynxptrgtzadmpfdkphfjhdulhzncoofmmrwqjxeyhodfavcgpjmohohuztezdxegqzbaaobzrqptuqsvwnfdneyccbkgkjafztytwuppvleukdqqzyeiltsvoqbxupbasiityganofxijucwzqgtdyxljociwwjdrnfnfbwyymmvbuvbrdnvcubzkohknbsneutrcukfiqqhfviqdsbtrldipenqifdcrenpuyaqvkparycksurhbtjppwhezbcgocamurdawimkzzkmiwadrumacogcbzehwppjtbhruskcyrapkvqayupnercdfiqnepidlrtbsdqivfhqqifkucrtuensbnkhokzbucvndrbvubvmmyywbfnfnrdjwwicojlxydtgqzwcujixfonagytiisabpuxbqovstlieyzqqdkuelvppuwtytzfajkgkbccyendfnwvsqutpqrzboaabzqgexdzetzuhohomjpgcvafdohyexjqwrmmfoocnzhludhjfhpkdfpmdaztgrtpxnyokknkukjfzvvuedqxelkrzpjtarvzocqconlgmpozoumbounpjphdpweshedfitlegqrmkvgklrjdtguvfprzrvxcfkifljlxefqiibinrgoyrjnbscptfoxtvoegvwmjdtxzsrznlbzom";
    CHECK(leetcode_5::longestPalindrome(str) == str);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
