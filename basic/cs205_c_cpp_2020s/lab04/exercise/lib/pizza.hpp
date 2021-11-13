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
#ifndef _LAB04_PIZZA_
#define _LAB04_PIZZA_

#include <iostream>
#include <cstring>

static constexpr const int32_t lab04_01_max_length = 1024;

class pizza {
public:
    char *name{nullptr};
    double *diameter{nullptr};
    double *weight{nullptr};

    pizza();

    pizza(char *n, double d, double w);

    ~pizza();
};

#endif //  _LAB04_PIZZA_
