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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP

#include <tuple>
#include <vector>
#include <cstdint>

namespace binary_search {
using std::tie;
using std::tuple;
using std::vector;
using std::vector;
using num_t = int32_t;

// !IMPORTANT [first,last)!!
// nums升序,寻找[first,last)内,第一个不小于value的值（x>=value的第一个)
num_t lower_bound(vector<num_t> &nums, num_t first, num_t last, num_t value);

// nums升序,寻找[first,last)内,任意等于value的值.
// 任意!
num_t any_equal(vector<num_t> &nums, num_t first, num_t last, num_t value);

// nums升序,寻找[first,last)内,第一个大于value的值（x>value的第一个)
num_t upper_bound(vector<num_t> &nums, num_t first, num_t last, num_t value);

// 升序,[first,last)内,最后一个小于value的值（x<value的最大值）
num_t lower_bound_warpper(vector<num_t> &nums, num_t first, num_t last, num_t value);

//升序,[first,last)内,最后一个小于等于value的值,(x<=value 最大值)
num_t upper_bound_warpper(vector<num_t> &nums, num_t first, num_t last, num_t value);

num_t binary_search_pos(std::vector<int32_t> vec, int32_t target, int32_t begin, int32_t end);
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP
