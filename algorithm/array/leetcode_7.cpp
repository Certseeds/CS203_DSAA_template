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
#include "leetcode_7_test.hpp"

namespace leetcode_7 {

int leetcode_7::reverse(int32_t x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -reverse3(-x);
    }
    std::array<uint8_t, 10> nums{0};
    int32_t count{0};
    while (x > 0) {
        nums[count] = x % 10;
        x /= 10;
        count++;
    }
    int32_t i{0};
    while (i < count && nums[i] == 0) {
        i++;
    }
    int32_t will_return = 0;
    for (; i < count; i++) {
        if(will_return  > (std::numeric_limits<int32_t>::max() -  nums[i]) /10){
            return 0;
        }
        will_return = will_return * 10 + nums[i];
    }
    return static_cast<int32_t>(will_return);
    // 不用64bit版
}


int leetcode_7::reverse2(int x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -1 * reverse3(-x);
    }
    vector<int> nums;
    while (x > 0) {
        nums.push_back(x % 10);
        x /= 10;
    }
    int32_t i{0};
    while (i < static_cast<int>(nums.size()) && nums[i] == 0) {
        i++;
    }
    long will_return = 0;
    for (; i < static_cast<int>(nums.size()); i++) {
        will_return = will_return * 10 + nums[i];
        if (will_return > std::numeric_limits<int32_t>::max()) {
            return 0;
        }
    }
    return static_cast<int32_t>(will_return);
}


int leetcode_7::reverse3(int x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -reverse3(-x);
    }
    vector<uint8_t> vec;
    vec.reserve(32);
    while (x > 0) {
        vec.push_back(x % 10);
        x /= 10;
    }
    int32_t will_return = 0;
    for (const auto &i: vec) {
        if (will_return > std::numeric_limits<int32_t>::max() / 10) {
            return 0;
        }
        will_return = 10 * will_return + i;
    }
    return will_return;
}
}