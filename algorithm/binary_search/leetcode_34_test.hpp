// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
//@Plan 剑指OfferII-I Day04
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP

#include <catch_main.hpp>
#include "basic.hpp"
#include <vector>

namespace leetcode_34 {
using std::vector;

struct leetcode_34 {
    static vector<int> searchRange(const vector<int> &nums, int target);
};

TEST_CASE("test case 1", "[test leetcode_34]") {
    const vector<int> vec0{};
    const vector<int> vec1{5, 7, 7, 8, 8, 10};
    assert(leetcode_34::searchRange(vec1, 8)[0] == 3 && leetcode_34::searchRange(vec1, 8)[1] == 4);
    assert(leetcode_34::searchRange(vec1, 6)[0] == -1 && leetcode_34::searchRange(vec1, 6)[1] == -1);
    assert(leetcode_34::searchRange(vec0, 115)[0] == -1 && leetcode_34::searchRange(vec0, 6)[1] == -1);
}

}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP
