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
#include "leetcode_80_test.hpp"

namespace leetcode_80 {


int32_t leetcode_80::removeDuplicates(vector<int32_t> &nums) {
    size_t s{nums.size()};
    if (s <= 2) {
        return static_cast<int32_t>(s);
    }
    int32_t number{nums[0]};
    size_t number_c{1}, insert_count{0}, count{1};
    while (count < s) {
        if (number == nums[count]) {
            number_c++;
            if (number_c == 2) {
                while (count < s && number == nums[count]) {
                    count++;
                }
            }
        } else {
            while (number_c > 0) {
                nums[insert_count] = number;
                insert_count++;
                number_c--;
            }
            number = nums[count];
            number_c = 1;
            count++;
        }
    }
    while (number_c > 0) {
        nums[insert_count] = number;
        insert_count++;
        number_c--;
    }
    return static_cast<int32_t>(insert_count);
}

}
