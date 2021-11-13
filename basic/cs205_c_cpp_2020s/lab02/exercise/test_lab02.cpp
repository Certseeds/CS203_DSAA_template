/**
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-25 21:20:01
 * @LastEditors  : nanoseeds
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
#define UNIT_TESTING_LAB_02

#include <catch_main.hpp>
#include "lab02_01.cpp"
#include "lab02_02.cpp"
#include "lab02_03.cpp"
#include <iostream>

using std::cout;
using std::endl;

TEST_CASE("test_lab03_01", "[run][.]") {
    sub_main_02_01();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_02", "[run][.]") {
    sub_main_02_02();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_03", "[run][.]") {
    sub_main_02_03();
    cin.get();
    cin.get();
}