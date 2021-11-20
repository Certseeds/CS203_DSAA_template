/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:44:50
 */
/* CS205_C_CPP
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
/**
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2020-03-26 18:10:42
 * @LastEditors  : nanoseeds
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
