// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:04:08
 * @LastEditors  : nanoseeds
 */
#include "number.h"

Number Number::operator++() { // 前缀
    return Number(++number);
}

Number Number::operator++(int) {
    return Number(number++);
}

Number Number::operator--() { // 前缀
    return Number(--number);
}

Number Number::operator--(int) {
    return Number(number--);
}

std::ostream &operator<<(std::ostream &os, const Number &other) {
    os << "x = " << other.number;
    return os;
}
