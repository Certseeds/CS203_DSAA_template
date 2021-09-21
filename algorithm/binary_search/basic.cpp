#include <catch_main.hpp>

#include <algorithm>
#include <tuple>
#include <vector>


using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::tie;
using std::tuple;
using std::vector;

using std::vector;
using num_t = int32_t;

// !IMPORTANT [first,last)!!
// nums升序,寻找[first,last)内,第一个不小于value的值（x>=value的第一个)
num_t lower_bound(vector<num_t> &nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        num_t middle = first + (last - first) / 2;
        if (nums[middle] < value) {
            first = middle + 1;
        } else if (nums[middle] >= value) {
            last = middle;
        }
    }
    return first;
}

TEST_CASE("lower_bound", "[test basic binary search]") {
    vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<num_t, num_t>> input_result = {
            {1, 0},
            {2, 2},
            {3, 3},
            {4, 4},
            {5, 7},
            {6, 9}};
    for (const auto &i: input_result) {
        num_t input{0};
        num_t output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound(vec, 0, vec.size(), input));
    }
}

// nums升序,寻找[first,last)内,任意等于value的值.
// 任意!
num_t any_equal(vector<num_t> &nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        num_t middle = first + (last - first) / 2;
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
    vector<num_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    vector<tuple<num_t, num_t, num_t>> input_result = {
            {1, 0,  1},
            {2, 1,  3},
            {3, 3,  6},
            {4, 6,  10},
            {5, 10, 15},
            {6, 15, 16}};
    // 0 2 4 8 12 15
    for (const auto &i: input_result) {
        num_t input{0};
        num_t left{0};
        num_t right{0};
        tie(input, left, right) = i;
        num_t result = any_equal(vec, 0, vec.size(), input);
        CHECK(result >= left);
        CHECK(result < right);
    }
}

// nums升序,寻找[first,last)内,第一个大于value的值（x>value的第一个)
num_t upper_bound(vector<num_t> &nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        num_t middle = first + (last - first) / 2;
        if (!(nums[middle] > value)) {
            first = middle + 1;
        } else if (nums[middle] > value) {
            last = middle;
        }
    }
    return first;
}

TEST_CASE("upper_bound", "[test basic binary search]") {
    vector<num_t> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6};
    vector<tuple<num_t, num_t>> input_result = {
            {1, 1},
            {2, 3},
            {3, 6},
            {4, 10},
            {5, 15},
            {6, 16}};
    for (const auto &i: input_result) {
        num_t input{0};
        num_t output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound(vec, 0, vec.size(), input));
    }
}

// 升序,[first,last)内,最后一个小于value的值（x<value的最大值）
num_t lower_bound_warpper(vector<num_t> &nums, num_t first, num_t last, num_t value) {
    return lower_bound(nums, first, last, value) - 1;
}

TEST_CASE("lower_bound_warpper", "[test basic binary search]") {
    vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<num_t, num_t>> input_result = {
            {1, -1},
            {2, 1},
            {3, 2},
            {4, 3},
            {5, 6},
            {6, 8}};
    for (const auto &i: input_result) {
        num_t input{0};
        num_t output{0};
        tie(input, output) = i;
        CHECK(output == lower_bound_warpper(vec, 0, vec.size(), input));
    }
}

//升序,[first,last)内,最后一个小于等于value的值,(x<=value 最大值)
num_t upper_bound_warpper(vector<num_t> &nums, num_t first, num_t last, num_t value) {
    return upper_bound(nums, first, last, value) - 1;
}

TEST_CASE("upper_bound_warpper", "[test basic binary search]") {
    vector<num_t> vec{1, 1, 2, 3, 4, 4, 4, 5, 5, 6};
    vector<tuple<num_t, num_t>> input_result = {
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 6},
            {5, 8},
            {6, 9}};
    for (const auto &i: input_result) {
        num_t input{0};
        num_t output{0};
        tie(input, output) = i;
        CHECK(output == upper_bound_warpper(vec, 0, vec.size(), input));
    }
}