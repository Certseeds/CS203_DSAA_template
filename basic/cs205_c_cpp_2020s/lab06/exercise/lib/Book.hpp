// SPDX-License-Identifier: AGPL-3.0-or-later
/* CS205_C_CPP
    Copyright (C) 2020-2023 nanoseeds
*/
/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:44:50
 */
#ifndef CS205_C_CPP_LAB06_EXERCISE_INCLUDE_BOOK_H
#define CS205_C_CPP_LAB06_EXERCISE_INCLUDE_BOOK_H


#include <cstdint>

class Book {
public:
    int32_t uuid{0};
    double height{11.4f};
    double length{51.4f};

    constexpr Book() = default;

    constexpr explicit Book(int32_t uuid_in) : uuid(uuid_in) {}

    constexpr Book(int32_t uuid_in, double height_in, double length_in) :
            uuid(uuid_in), height(height_in), length(length_in) {}

    ~Book() = default;

    Book(const Book &) = delete;

    Book &operator=(const Book &) = delete;

    int Get_Uuid() const;

    double Get_Area() const;
};


#endif //CS205_C_CPP_LAB06_EXERCISE_INCLUDE_BOOK_H
