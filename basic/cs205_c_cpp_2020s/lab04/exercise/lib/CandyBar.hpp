/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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