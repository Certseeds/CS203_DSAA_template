/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_HPP

#include <catch_main.hpp>
#include <vector>

namespace leetcode_33 {
using std::vector;

struct leetcode_33 {
    static int search(vector<int> &nums, int target);
};

TEST_CASE("1 [test_33]", "[test_33]") {
    vector<int> vec1{4, 5, 6, 7, 8, 0, 1, 2};
    vector<int> vec2{4, 5, 6, 7, 8, 9, 0, 1, 2};
    vector<int> vec3{4, 5, 6, 7, 8, 9, 10, 0, 1, 2};
    vector<int> vec4{4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
    vector<int> vec5{4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2};
    vector<int> vec6{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2};
    vector<int> vec7{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 1, 2};
    vector<int> vec8{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2};
    vector<int> vec9{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2};
    //cout << binary_search_pos(vec1, 8, 0, 4) << endl;
    vector<int> vec10{
            49, 64, 66, 67, 68, 69, 71, 74, 76, 78, 83, 86, 91, 93, 94, 96, 97, 106, 113, 11,
            6, 118, 119, 120, 121, 122, 123, 125, 126, 129, 131, 132, 141, 142, 144, 146, 14,
            7, 156, 157, 167, 170, 171, 172, 178, 183, 185, 188, 191, 192, 196, 209, 210, 211,
            213, 221, 226, 228, 230, 233, 235, 236, 237, 242, 243, 246, 247, 250, 251, 252,
            256, 261, 266, 267, 272, 275, 286, 289, 291, 296, 299,
            0, 7, 8, 9, 14, 16, 21, 35, 37, 41, 44, 45, 47, 48};
    CHECK(leetcode_33::search(vec1, 8) == 4);
    CHECK(leetcode_33::search(vec2, 9) == 5);
    CHECK(leetcode_33::search(vec3, 3) == -1);
    CHECK(leetcode_33::search(vec4, 2) == 10);
    CHECK(leetcode_33::search(vec5, 7) == 3);
    CHECK(leetcode_33::search(vec6, 24) == -1);
    CHECK(leetcode_33::search(vec7, 13) == 9);
    CHECK(leetcode_33::search(vec8, 1) == 13);
    CHECK(leetcode_33::search(vec9, 0) == 13);
    CHECK(leetcode_33::search(vec10, 35) == 88);
}
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_HPP