// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_26 {
using std::vector;

struct leetcode_26 {
    static int removeDuplicates(vector<int> &nums);

};

using Catch::Matchers::Equals;


TEST_CASE("1 [test_26]", "[test_26]") {
    vector<int32_t> vec{1, 2};
    const vector<int32_t> result{1, 2};
    THEN("then1 [test_26]") {
        leetcode_26::removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("2 [test_26]", "[test_26]") {
    vector<int32_t> vec{1, 1, 2};
    const vector<int32_t> result{1, 2};
    THEN("then3 [test_26]") {
        leetcode_26::removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("3 [test_26]", "[test_26]") {
    vector<int32_t> vec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const vector<int32_t> result{0, 1, 2, 3, 4};
    THEN("then5 [test_26]") {
        leetcode_26::removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP
