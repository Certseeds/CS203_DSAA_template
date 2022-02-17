/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
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
//@Description 最长公共子序列

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1143 {
using std::string;

struct leetcode_1143 {
    static int32_t longestCommonSubsequence(const string &text1, const string &text2);

    static int32_t longestCommonSubsequence2(const string &text1, const string &text2);
};

TEST_CASE("1 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abcde"}, *const input2{"ace"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("2 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abc"}, *const input2{"abc"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("3 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abc"}, *const input2{"degf"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("4 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"a"}, *const input2{"aba"};
    static constexpr const auto result{1};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("5 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{
            "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"};
    static constexpr const char *const input2{
            "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan"};
    static constexpr const auto result{323};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("6 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"bsbininm"}, *const input2{"jmjkbkjkv"};
    static constexpr const auto result{1};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("7 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"horse"}, *const input2{"ros"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}

TEST_CASE("8 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"intention"}, *const input2{"execution"};
    static constexpr const auto result{5}; // etion
    CHECK(result == leetcode_1143::longestCommonSubsequence(input1, input2));
    CHECK(result == leetcode_1143::longestCommonSubsequence2(input1, input2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP
