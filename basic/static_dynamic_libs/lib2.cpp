// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "lib2.hpp"
#include "lib1.hpp"
#include <cstdint>
#include <iostream>

int32_t function2() {
    std::cout << function1() + 1 << std::endl;
    return function1() + 1;
}
