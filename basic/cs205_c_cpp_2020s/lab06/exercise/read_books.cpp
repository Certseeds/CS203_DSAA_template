// SPDX-License-Identifier: AGPL-3.0-or-later
/* CS205_C_CPP
    Copyright (C) 2020-2022 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-26 18:16:22
 * @LastEditors  : nanoseeds
 */
#include "Book.hpp"
#include <iostream>

int32_t main() {
    static constexpr const Book book1{1, 4, 5};
    std::cout << book1.Get_Area() << std::endl;
}