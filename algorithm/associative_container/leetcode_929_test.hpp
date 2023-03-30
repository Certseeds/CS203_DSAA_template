// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash函数
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_929_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_929_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_929 {
using std::array;
using std::vector;

struct leetcode_929 {
    static int32_t numUniqueEmails(const vector<string> &emails);
};



TEST_CASE("test case 1 {test_929}", "{test_929}") {
    static constexpr const std::array<const char *const, 3> arr{
            "114.51419+1981@0893.996", "114.5.1419+251.666@0893.996", "11451419+8888@08.93.996"
    };
    static constexpr const auto result{2};
    CHECK(result == leetcode_929::numUniqueEmails({arr.begin(), arr.end()}));
}

TEST_CASE("test case 2 {test_929}", "{test_929}") {
    static constexpr const std::array<const char *const, 3> arr{
            "9@0hello.world", "5@hello.world", "4@hello.world"
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_929::numUniqueEmails({arr.begin(), arr.end()}));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_929_TEST_HPP
