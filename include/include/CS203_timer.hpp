/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:42:36
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_TIMER_HPP
#define CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_TIMER_HPP

#include <iostream>
#include <chrono>
#include <class_helper/nonable.hpp>

std::chrono::milliseconds get_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
}

class CS203_timer final : private nonCopyMoveAble {
private:
    std::chrono::milliseconds ms{get_ms()};
public:
    CS203_timer() = default;

    ~CS203_timer() {
        std::cout << "cost " << get_ms().count() - ms.count() << " ms\n";
    }
};

#endif //CS203_DSAA_TEMPLATE_INCLUDE_INCLUDE_CS203_TIMER_HPP
