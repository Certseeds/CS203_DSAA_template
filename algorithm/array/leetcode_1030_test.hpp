// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 排序
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1030 {
using std::vector;

struct leetcode_1030 {
    static vector<vector<int32_t>> allCellsDistOrder(int32_t rows, int32_t cols, int32_t rCenter, int32_t cCenter);

    static vector<vector<int32_t>> allCellsDistOrderNLogN(int32_t rows, int32_t cols, int32_t rCenter, int32_t cCenter);
};

bool check(const vector<vector<int32_t>> &input, int32_t rCenter, int32_t cCenter) {
    vector<int32_t> test{};
    for (const auto &point: input) {
        test.push_back(std::abs(rCenter - point[0]) + std::abs(cCenter - point[1]));
    }
    return std::is_sorted(test.cbegin(), test.cend());
}

TEST_CASE("test case 3-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{3}, rCenter{1}, cCenter{2};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 3-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{3}, rCenter{1}, cCenter{2};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 2-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{2}, rCenter{0}, cCenter{1};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 2-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{2}, rCenter{0}, cCenter{1};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 1-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{1}, cols{2}, rCenter{0}, cCenter{0};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 1-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{1}, cols{2}, rCenter{0}, cCenter{0};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 4-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{11}, cols{45}, rCenter{1}, cCenter{4};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 4-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{11}, cols{45}, rCenter{1}, cCenter{4};
    const vector<vector<int32_t>> result{leetcode_1030::allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP
