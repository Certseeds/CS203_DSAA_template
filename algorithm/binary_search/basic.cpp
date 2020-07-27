/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-27 15:50:42
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-27 17:04:35
 */

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "catch_main.hpp"
using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::cout;
using std::endl;
using std::tie;
using std::tuple;
using std::vector;

using std::vector;
// nums升序，寻找[first,last)内，第一个不小于value的值（x>=value的第一个)
int lower_bound(vector<int32_t> nums, int32_t first, int32_t last, int value) {
    while (first < last) {
        int middle = first + (last - first) / 2;
        if (nums[middle] < value) {
            first = middle + 1;
        } else if (nums[middle] >= value) {
            last = middle;
        }
    }
    return first;
}
TEST_CASE("lower_bound", "[test basic binary search]") {
    vector<int32_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<int32_t, int32_t>> input_result = {
        {1, 0}, {2, 2}, {3, 3}, {4, 4}, {5, 7}, {6, 9}};
    for (const auto& i : input_result) {
        int input{0};
        int output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound(vec, 0, vec.size(), input));
    }
}
// nums升序，寻找[first,last)内，任意等于value的值.
// 任意！
int any_equal(vector<int32_t> nums, int32_t first, int32_t last, int value) {
    while (first < last) {
        int middle = first + (last - first) / 2;
        if (nums[middle] == value) {
            return middle;
        } else if (nums[middle] < value) {
            first = middle + 1;
        } else if (nums[middle] > value) {
            last = middle;
        }
    }
    return first;
}
TEST_CASE("any_equal", "[test basic binary search]") {
    vector<int32_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    vector<tuple<int32_t, int32_t, int32_t>> input_result = {
        {1, 0, 1}, {2, 1, 3}, {3, 3, 6}, {4, 6, 10}, {5, 10, 15}, {6, 15, 16}};
    // 0 2 4 8 12 15
    for (const auto& i : input_result) {
        int32_t input{0};
        int32_t left{0};
        int32_t right{0};
        tie(input, left, right) = i;
        int32_t result = any_equal(vec, 0, vec.size(), input);
        CHECK(result >= left);
        CHECK(result < right);
    }
}
// nums升序，寻找[first,last)内，第一个大于value的值（x>value的第一个)
int upper_bound(vector<int32_t> nums, int32_t first, int32_t last, int value) {
    while (first < last) {
        int middle = first + (last - first) / 2;
        if (!(nums[middle] > value)) {
            first = middle + 1;
        } else if (nums[middle] > value) {
            last = middle;
        }
    }
    return first;
}
TEST_CASE("upper_bound", "[test basic binary search]") {
    vector<int32_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    vector<tuple<int32_t, int32_t>> input_result = {
        {1, 1}, {2, 3}, {3, 6}, {4, 10}, {5, 15}, {6, 16}};
    for (const auto& i : input_result) {
        int input{0};
        int output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound(vec, 0, vec.size(), input));
    }
}
// 升序，【first,last)内，最后一个小于value的值（x<value的最大值）
int lower_bound_warpper(vector<int32_t> nums, int32_t first, int32_t last, int value) {
    return lower_bound(nums, first, last, value) - 1;
}
TEST_CASE("lower_bound_warpper", "[test basic binary search]") {
    vector<int32_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<int32_t, int32_t>> input_result = {
        {1, -1}, {2, 1}, {3, 2}, {4, 3}, {5, 6}, {6, 8}};
    for (const auto& i : input_result) {
        int input{0};
        int output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound_warpper(vec, 0, vec.size(), input));
    }
}
//升序，【first,last)内，最后一个小于等于value的值，(x<=value 最大值)
int upper_bound_warpper(vector<int32_t> nums, int32_t first, int32_t last, int value) {
    return upper_bound(nums, first, last, value) - 1;
}
TEST_CASE("upper_bound_warpper", "[test basic binary search]") {
    vector<int32_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<int32_t, int32_t>> input_result = {
        {1, 1}, {2, 2}, {3, 3}, {4, 6}, {5, 8}, {6, 9}};
    for (const auto& i : input_result) {
        int input{0};
        int output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound_warpper(vec, 0, vec.size(), input));
    }
}