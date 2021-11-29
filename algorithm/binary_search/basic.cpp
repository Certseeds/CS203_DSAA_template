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

#include "basic.hpp"

namespace binary_search {

// !IMPORTANT [first,last)!!
// nums升序,寻找[first,last)内,第一个不小于value的值（x>=value的第一个)
num_t lower_bound(cVecRef nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        //C++17特性, middle作用域局限在了if-else 语句中
        if (const num_t middle{first + (last - first) / 2};
                nums[middle] < value) {
            first = middle + 1;
        } else if (nums[middle] >= value) {
            last = middle;
        }
    }
    return first;
}


// nums升序,寻找[first,last)内,任意等于value的值.
// 任意!
num_t any_equal(cVecRef nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        if (const num_t middle{first + (last - first) / 2};
                nums[middle] == value) {
            return middle;
        } else if (nums[middle] < value) {
            first = middle + 1;
        } else if (nums[middle] > value) {
            last = middle;
        }
    }
    return first;
}

// nums升序,寻找[first,last)内,第一个大于value的值（x>value的第一个)
num_t upper_bound(cVecRef nums, num_t first, num_t last, num_t value) {
    while (first < last) {
        if (const num_t middle{first + (last - first) / 2};
                nums[middle] <= value) {
            first = middle + 1;
        } else if (nums[middle] > value) {
            last = middle;
        }
    }
    return first;
}

num_t lower_bound_warpper(cVecRef nums, num_t first, num_t last, num_t value) {
    return lower_bound(nums, first, last, value) - 1;
}

//升序,[first,last)内,最后一个小于等于value的值,(x<=value 最大值)
num_t upper_bound_warpper(cVecRef nums, num_t first, num_t last, num_t value) {
    return upper_bound(nums, first, last, value) - 1;
}

int32_t binary_search_pos(cVecRef vec, int32_t target, int32_t begin, int32_t end) {
    // it is [begin,end),length is end-begin
    int32_t middle{0};
    while (begin < end) {
        middle = (end - begin) / 2 + begin;
        if (vec[middle] < target) {
            begin = middle + 1;
        } else if (target == vec[middle]) {
            return middle;
        } else {
            end = middle;
        }
    }
    return -1;
}

}