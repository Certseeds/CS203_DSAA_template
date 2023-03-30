// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_263_test.hpp"

namespace leetcode_263 {
bool isUgly2(const int32_t n) {
    if (n <= 6) {
        return true;
    } else if (n % 2 == 0) {
        return isUgly2(n >> 1);
    } else if (n % 3 == 0) {
        return isUgly2(n / 3);
    } else if (n % 5 == 0) {
        return isUgly2(n / 5);
    }
    return false;
}

bool leetcode_263::isUgly(int32_t n) {
    if (n <= 0) {
        return false;
    }
    return isUgly2(n);
}

}
