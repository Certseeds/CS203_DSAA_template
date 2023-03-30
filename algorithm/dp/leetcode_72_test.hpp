// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 最小路径和
//@Plan 动态规划入门 Day19
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_72_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_72_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_72 {
using std::string;

struct leetcode_72 final {
    static int32_t minDistance(const string &word1, const string &word2);
};


TEST_CASE("1 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"abcde"}, *const input2{"ace"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("2 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"abc"}, *const input2{"abc"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("3 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"abc"}, *const input2{"degf"};
    static constexpr const auto result{4};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("4 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"a"}, *const input2{"aba"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("5 [test_72]", "[test_72]") {
    static constexpr const char *const input1{
            "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"};
    static constexpr const char *const input2{
            "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan"};
    static constexpr const auto result{856};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("6 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"bsbininm"}, *const input2{"jmjkbkjkv"};
    static constexpr const auto result{9};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("7 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"horse"}, *const input2{"ros"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_72::minDistance(input1, input2));
}

TEST_CASE("8 [test_72]", "[test_72]") {
    static constexpr const char *const input1{"intention"}, *const input2{"execution"};
    static constexpr const auto result{5}; // etion
    CHECK(result == leetcode_72::minDistance(input1, input2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_72_TEST_CPP
