// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_CATCH_MAIN_H
#define CS203_DSAA_TEMPLATE_INCLUDES_CATCH_MAIN_H
//#define CATCH_CONFIG_MAIN

#ifndef CATCH_AMALGAMATED_HPP_INCLUDED

#include <catch_amalgamated.hpp>

#pragma message("import catch_amalgamated.hpp")
// find this in ide's autolight
#else
#pragma message("use pre-compiled")
// output this while compile
// 兼容MSVC
#endif

#include <public.hpp>

static const CS203_timer timer{};

#endif //CS203_DSAA_TEMPLATE_INCLUDES_CATCH_MAIN_H
