// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2023 nanoseeds
*/
#ifndef _LAB04_CANDYBAR_
#define _LAB04_CANDYBAR_

#include <string>
#include <cstring>

static constexpr const int32_t lab04_02_maxrange = 1024;

struct CandyBar {
    char *name{nullptr};
    double *weight{nullptr};
    int32_t *calories{nullptr};

    CandyBar();

    CandyBar(char *n, double d, int32_t w);

    ~CandyBar();
};

#endif //!_LAB04_CANDYBAR_
