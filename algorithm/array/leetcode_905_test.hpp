// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_905 {
using std::vector;

struct leetcode_905 {
private:
    static vector<int32_t> sortArrayByParity(vector<int> &nums);

public:
    static vector<int32_t> sortArrayByParity2(const vector<int> &nums) {
        vector<int32_t> will_return{nums};
        sortArrayByParity(will_return);
        return will_return;
    }
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_905}", "{test_905}") {
    const vector<int32_t> input{3, 1, 2, 4};
    const vector<int32_t> result{2, 4, 3, 1};
    CHECK_THAT(result, Equals(leetcode_905::sortArrayByParity2(input)));
}

TEST_CASE("test case 2 {test_905}", "{test_905}") {
    const vector<int32_t> input{0};
    const vector<int32_t> result{0};
    CHECK_THAT(result, Equals(leetcode_905::sortArrayByParity2(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP
