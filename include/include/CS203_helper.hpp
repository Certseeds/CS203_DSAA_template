/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:48:30
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 * @LastEditTime: 2021-01-03 21:45:55
 */
/*
MIT License


CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
static constexpr const double eps{0.00000001}, neps{-eps};

constexpr inline int32_t sign(int32_t x) {
    return ((x > 0) - (x < 0));
}

constexpr inline int32_t sign(double x) {
    return ((x < neps) ? -1 : (x > neps));
}

#endif //CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
