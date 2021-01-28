/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:57:16 
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
#include <vector>
#include <iostream>
#include <cstring>
#include "sort_wrapper.hpp"

using std::vector;

void merge_sort(vector<int32_t> &nums);

void mergesort_rec(vector<int32_t> &nums, vector<int32_t> &zeros, int begin, int end);

void sort_warpper(vector<int32_t> &nums) {
    merge_sort(nums);
}

void merge_sort(vector<int32_t> &nums) {
    vector<int32_t> zeros(nums);
    mergesort_rec(nums, zeros, 0, nums.size() - 1);
}

void mergesort_rec(vector<int32_t> &nums, vector<int32_t> &zeros, int begin, int end) {
    if (begin >= end) {
        return;
    } else if (begin + 1 == end) {
        if (nums[begin] > nums[end]) {
            std::swap(nums[begin], nums[end]);
        }
    }
    int middle = begin + (end - begin) / 2;;
    mergesort_rec(nums, zeros, begin, middle);
    mergesort_rec(nums, zeros, middle + 1, end);
    int pos = begin;
    int start1 = begin;
    int start2 = middle + 1;
    while (start1 <= middle && start2 <= end) {
        if (nums[start1] < nums[start2]) {
            zeros[pos] = nums[start1];
            start1++;
        } else {
            zeros[pos] = nums[start2];
            start2++;
        }
        pos++;
    }
    while (start1 <= middle) {
        zeros[pos] = nums[start1];
        pos++;
        start1++;
    }
    while (start2 <= end) {
        zeros[pos] = nums[start2];
        pos++;
        start2++;
    }
    memcpy(reinterpret_cast<void *>(&nums[begin]), reinterpret_cast<void *>(&zeros[begin]),
           sizeof(int32_t) * (end - begin + 1));
}