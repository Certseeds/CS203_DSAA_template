// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_657_test.hpp"

namespace leetcode_657 {

bool leetcode_657::judgeCircle(const string &moves) {
    int32_t x{0}, y{0};
    for (size_t i{0}, moves_size{moves.size()}; i < moves_size; ++i) {
        switch (moves[i]) {
            case ('L'): {
                x++;
                break;
            }
            case ('R'): {
                x--;
                break;
            }
            case ('U'): {
                y++;
                break;
            }
            case ('D'): {
                y--;
                break;
            }
        }
    }
    return (x == 0 && y == 0);
}
}
