/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-01 17:33:49
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <algorithm>
#include <numeric>
#include <tuple>
#include <vector>

#include "catch_main.hpp"

using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::tie;
using std::tuple;
using std::vector;
using num_t = int32_t;

// nums应该为一个先增后减,极大值在中心的数组
// 此函数目的在于寻找其中间的最大值,[first,last]
num_t triple_search(vector<num_t> &nums, num_t first, num_t last) {
    while (first < last - 1) {
        num_t middle = (last - first) / 2 + first;
        num_t right_middle = (last - middle) / 2 + middle;
        if (nums[middle] > nums[right_middle]) {
            last = right_middle - 1;
        } else if (nums[middle] < nums[right_middle]) {
            first = middle + 1;
        } else {
            last--;
        }
    }
    return std::max(nums[first], nums[last]);
}

const static auto func_factory = [](num_t w, num_t x, num_t y) {
    return [w, x, y](num_t z) -> num_t {
        return -1 * w * (z - x) * (z - x) + y;
    };
    // 一个工厂方法,用于生产二次函数
};

TEST_CASE("test case 1", "[test binary search- triple search]") {
    constexpr num_t ratio = 1;    // y = -1 * ratio * Math.pow((x-middle),2) + diff
    constexpr num_t first = 0;    // begin of array
    constexpr num_t middle = 30;  // max value's index
    constexpr num_t last = 100;   // last of array
    constexpr num_t diff = 450;   // max value of array
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //std::cout << '\n';
    // prepare data finish
    //cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 2", "[test binary search- triple search]") {
    constexpr num_t ratio = 3, first = 0, middle = 70, last = 100, diff = 514;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //     std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //     std::cout << '\n';
    //     prepare data finish
    //      cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 3", "[test binary search- triple search]") {
    constexpr num_t ratio = 200, first = 0, middle = 50, last = 100, diff = -200;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //    std::cout << '\n';
    //     prepare data finish
    //    cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 4", "[test binary search- triple search]") {
    constexpr num_t ratio = 3, first = 10, middle = 60, last = 80, diff = 119;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //std::cout << '\n';
    // prepare data finish
    //cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}