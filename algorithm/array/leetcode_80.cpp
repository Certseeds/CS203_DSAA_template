// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

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
