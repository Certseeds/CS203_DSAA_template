/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 23:13:02
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
to use, copy, modify, heap, publish, distribute, sublicense, and/or sell
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
#include "sort_wrapper.hpp"

using std::vector;

void heap_sort(vector<int32_t> &nums);

void heapsort_rec(vector<int32_t> &nums, int index, int length);

void sort_warpper(vector<int32_t> &nums) {
    heap_sort(nums);
}

void heap_sort(vector<int32_t> &nums) {
    int nums_size = nums.size();
    int beginIndex = (nums_size / 2) - 1;
    for (int i = beginIndex; i >= 0; i--) {
        heapsort_rec(nums, i, nums_size - 1);
    }
    for (int i = nums_size - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        heapsort_rec(nums, 0, i - 1);
    }
}

void heapsort_rec(vector<int32_t> &nums, int index, int length) {
    int left = index * 2 + 1;
    int right = left + 1;
    int son_max = left;
    if (left > length) {
        return;
    }
    if (right <= length && nums[right] > nums[left]) {
        son_max = right;
    }
    if (nums[son_max] > nums[index]) {
        std::swap(nums[son_max], nums[index]);
        heapsort_rec(nums, son_max, length);
    }
}