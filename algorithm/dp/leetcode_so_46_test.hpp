// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 剑指OfferII-I Day10
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_SO_46_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_SO_46_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_so_46 {

struct leetcode_so_46 {
    static int32_t translateNum(int32_t num);
};


TEST_CASE("1 [test_so_46]", "[test_so_46]") {
    static constexpr const auto input{12258};
    static constexpr const auto result{5};
    CHECK(result == leetcode_so_46::translateNum(input));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_SO_46_TEST_CPP
