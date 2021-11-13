/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-02-08 22:04:11
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:23:52
 */
/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#define UNIT_TESTING_ASSIGNMENT_1

#include <catch_main.hpp>
#include <assignment_1.hpp>

TEST_CASE("test_judge_legal", "[judge_legal]")
{
    REQUIRE(1 == judge_legal("Beijing "));
    REQUIRE(0 == judge_legal("Shang@hai"));
    REQUIRE(1 == judge_legal(""));
    REQUIRE(1 == judge_legal("New Yodk, USA"));
    REQUIRE(1 == judge_legal("London, UK"));
    REQUIRE(1 == judge_legal("Pairs, France"));
    REQUIRE(1 == judge_legal("Kolkata, India"));
    REQUIRE(1 == judge_legal("Moscow, Russia"));
    REQUIRE(1 == judge_legal("Rio de Janeiro, Brazil"));
    REQUIRE(0 == judge_legal("114514@gmail.comn"));
    REQUIRE(0 == judge_legal("C#come from microsoft"));
}

TEST_CASE("test_judge_legal_2", "[judge_legal]") {
    REQUIRE(1 == judge_legal2("+0.114514 -0.1919810"));
    REQUIRE(1 == judge_legal2("+1.114514 -0.1919810"));
    REQUIRE(1 == judge_legal2("+.114514 -.1919810"));
    REQUIRE(1 == judge_legal2("+1.14514 -1.919810"));
    REQUIRE(1 == judge_legal2("+11.4514 -19.19810"));
    REQUIRE(1 == judge_legal2("+114.514 -191.9810"));
    REQUIRE(1 == judge_legal2("+1145.14 -1919.810"));
    REQUIRE(1 == judge_legal2("+11451.4 -19198.10"));
    REQUIRE(1 == judge_legal2("+114514. -1919810."));
    REQUIRE(0 == judge_legal2("114514@gmail.comn"));
    REQUIRE(0 == judge_legal2("C#come from microsoft"));
}

TEST_CASE("delete_space", "[test]") {
    string str = "12345 678910";
    REQUIRE(str == delete_space("   12345 678910   "));
    REQUIRE(str == delete_space("12345 678910   "));
    REQUIRE(str == delete_space("   12345 678910"));
    REQUIRE(str == delete_space("12345 678910"));
    REQUIRE(delete_space("").empty());
}

TEST_CASE("test_splits", "[test]") {
    string str = "12345 678910";
    REQUIRE("12345" == str.substr(0, str.find_first_of(' ')));
    REQUIRE(" 678910" == str.substr(str.find_first_of(' '), str.size()));
}

TEST_CASE("test_check_double", "[test]") {
    REQUIRE(1 == check_double("1123"));
    REQUIRE(1 == check_double("-1.123"));
    REQUIRE(1 == check_double("+1.123"));
    REQUIRE(1 == check_double("+1.123"));
    REQUIRE(1 == check_double("-0.1123"));
    REQUIRE(1 == check_double("-.1123"));
}

TEST_CASE("test1", "[test]") {
}

TEST_CASE("mains", "[run][.]") {
    CHECK(0 == sub_main());
    cin.get();
    cin.get();
}
