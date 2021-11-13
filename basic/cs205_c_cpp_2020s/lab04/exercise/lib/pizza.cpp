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
#include "pizza.hpp"

pizza::pizza() {
    name = new char[lab04_01_max_length];
    memset(name, '\0', lab04_01_max_length);
    diameter = new double;
    weight = new double;
}

pizza::pizza(char *n, double d, double w) {
    name = new char[lab04_01_max_length];
    diameter = new double;
    weight = new double;
    memset(name, '\0', lab04_01_max_length);
    memcpy(name, n, strlen(n) * sizeof(char));
    (*diameter) = d;
    (*weight) = w;
}

pizza::~pizza() {
    delete[] name;
    delete diameter;
    delete weight;
}
