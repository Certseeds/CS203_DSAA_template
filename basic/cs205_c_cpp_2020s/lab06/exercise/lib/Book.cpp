// SPDX-License-Identifier: AGPL-3.0-or-later
/* CS205_C_CPP
    Copyright (C) 2020-2023 nanoseeds
*/
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-26 18:10:42
 * @LastEditors  : nanoseeds
 */
#include "Book.hpp"


double Book::Get_Area() const {
    return (this->height) * (this->length);
}

int Book::Get_Uuid() const {
    return this->uuid;
}
