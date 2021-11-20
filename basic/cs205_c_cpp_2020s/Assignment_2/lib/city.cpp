/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2021-02-08 22:48:30
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:49:10
 */
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
#include "city.hpp"

city::city() {
    city_name = new char[LENGTH_OF_NAME + 1];
    country_name = new char[LENGTH_OF_NAME + 1];
    latitude = new double;
    longitude = new double;
    memset(city_name, '\0', LENGTH_OF_NAME * sizeof(char));
    memset(country_name, '\0', LENGTH_OF_NAME * sizeof(char));
}

city::city(char *ci_name, char *coun_name, double la, double lo) {
    city_name = new char[LENGTH_OF_NAME + 1];
    country_name = new char[LENGTH_OF_NAME + 1];
    latitude = new double;
    longitude = new double;
    memset(city_name, '\0', LENGTH_OF_NAME + 1);
    memset(country_name, '\0', LENGTH_OF_NAME + 1);
    memcpy(city_name, ci_name, std::min(LENGTH_OF_NAME, static_cast<int>(strlen(ci_name))) * sizeof(char));
    memcpy(country_name, coun_name, std::min(LENGTH_OF_NAME, static_cast<int>(strlen(coun_name))) * sizeof(char));
    (*latitude) = la;
    (*longitude) = lo;
}

city::~city() {
    delete[] city_name;
    delete[] country_name;
    delete latitude;
    delete longitude;
}