// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Description 链表中点,经典双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP

#include <catch_main.hpp>

namespace leetcode_1409 {

namespace leetcode_1409 {
vector<int32_t> processQueries(const vector<int32_t> &queries, int32_t m);
}
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_1409]", "[test_1409]") {
    const vector<int32_t> vec1{3, 1, 2, 1};
    constexpr const auto m{5};
    const vector<int32_t> result{2, 1, 2, 1};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(vec1, m)));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP
