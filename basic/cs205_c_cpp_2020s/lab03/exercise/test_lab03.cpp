/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:51:49
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
#define UNIT_TESTING_LAB_03


#include <catch_main.hpp>
#include "./lab03_01.cpp"
#include "./lab03_02.cpp"
#include "./lab03_03.cpp"
#include <iostream>

using std::cout;
using std::endl;

TEST_CASE("test_lab03_01", "[run][.]") {
    sub_main_03_01();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_02", "[run][.]") {
    sub_main_03_02();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_03", "[run][.]") {
    sub_main_03_03();
    cin.get();
    cin.get();
}