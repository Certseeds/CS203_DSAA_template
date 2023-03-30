// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_559_test.hpp"

namespace leetcode_559 {

int leetcode_559::maxDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    int32_t maxvalue{0};
    for (const auto pointer: root->children) {
        maxvalue = std::max(maxvalue, maxDepth(pointer));
    }
    return maxvalue + 1;
}
}
