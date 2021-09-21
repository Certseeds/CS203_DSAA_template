/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-18 21:00:45
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-18 21:03:33
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

#include "sort_wrapper.hpp"

using std::vector;

void quick_sort(vector<int> &nums);

inline int get_rand(int left, int right);

void rec_quicksort(vector<int> &nums, int left, int right);

int partition(vector<int> &nums, int left, int right, int pivotIndex);

void sort_warpper(vector<int32_t> &nums) {
    quick_sort(nums);
}

void quick_sort(vector<int> &nums) {
    rec_quicksort(nums, 0, static_cast<int>(nums.size() - 1));
}

void rec_quicksort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int rand_posi = get_rand(left, right);
    int final_posi = partition(nums, left, right, rand_posi);
    rec_quicksort(nums, left, final_posi - 1);
    rec_quicksort(nums, final_posi + 1, right);
}

inline int get_rand(int left, int right) {
    return rand() % (right - left + 1) + left;
}

int partition(vector<int> &nums, int left, int right, int pivotIndex) {
    int pivotValue = nums[pivotIndex];
    std::swap(nums[pivotIndex], nums[right]); // 把pivot移到結尾
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (nums[i] <= pivotValue) {
            std::swap(nums[storeIndex], nums[i]);
            storeIndex++;
        }
    }
    std::swap(nums[right], nums[storeIndex]);
    return storeIndex;
}