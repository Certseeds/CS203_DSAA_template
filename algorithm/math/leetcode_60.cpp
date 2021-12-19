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
#include "leetcode_60_test.hpp"

namespace leetcode_60 {
constexpr int32_t facts(int32_t t) {
    int32_t will_return{1};
    for (int32_t x{1}; x <= t; x++) {
        will_return *= x;
    }
    return will_return;
}// c++ 14 constexpr, count facts in complier time.
string leetcode_60::getPermutation(int32_t n, int32_t k) {
    vector<int32_t> fact(10, 1);
    for (int32_t i{0}; i < 10; i++) {
        fact[i] = facts(i);
    }
    assert(fact[n] >= k && k >= 1);
    assert(1 <= n && n <= 9);
    vector<int32_t> nums;
    char will_return[10]{'\0'};
    int32_t k_count = k - 1;
    vector<int32_t> ordres;
    for (int32_t i{1}; i <= n; i++) {
        nums.push_back(i);
    }
    for (int32_t i{0}; i < n; i++) {
        int32_t temp = k_count / fact[n - 1 - i];
        ordres.push_back(temp);
        k_count = k_count % fact[n - 1 - i];
        will_return[i] = '0' + nums[ordres[i]];
        nums.erase(std::remove(nums.begin(), nums.end(), nums[ordres[i]]), nums.end());
    }
    return will_return;
}

string getPermutation_rec_in(int32_t n, int32_t k, vector<int32_t> nums) {
    vector<int32_t> fact(10, 1);
    for (int32_t i{0}; i < 10; i++) {
        fact[i] = facts(i);
    }
    assert(fact[n] >= k && k >= 0);
    assert(n >= 1 && n <= 9);
    char will_return[2];
    memset(will_return, '\0', sizeof(char) * 2);
    if (1 == n) {
        will_return[0] = '0' + nums[0];
        return will_return;
    }
    will_return[0] = '0' + nums[k / fact[n - 1]];
    nums.erase(std::remove(nums.begin(), nums.end(), will_return[0] - '0'), nums.end());
    return will_return + getPermutation_rec_in(n - 1, k % fact[n - 1], nums);
}

string leetcode_60::getPermutation_rec_out(int32_t n, int32_t k) {
    vector<int32_t> fact(10, 1);
    for (int32_t i{0}; i < 10; i++) {
        fact[i] = facts(i);
    }
    assert(fact[n] >= k && k >= 1);
    assert(n >= 1 && n <= 9);
    vector<int32_t> nums;
    for (int32_t i{1}; i <= n; i++) {
        nums.push_back(i);
    }
    return getPermutation_rec_in(n, k - 1, nums);
}


}