// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-19 22:23:46
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_02.hpp"

int32_t question2() {
    // output
    for (const auto &i: umap) {
        // int32_t times = ;
        if (std::count(i.second.begin(), i.second.end(), 0) >= 2) {
            // cout << i.first << " " << "Absent " << times << " times" << endl;
            cout << i.first << endl;
        }
    }
    return 0;
}