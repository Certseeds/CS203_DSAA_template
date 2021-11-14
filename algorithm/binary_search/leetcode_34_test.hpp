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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_HPP

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


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_HPP
