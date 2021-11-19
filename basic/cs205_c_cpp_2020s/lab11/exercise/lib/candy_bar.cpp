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
/**
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2020-04-30 19:59:02
 * @LastEditors  : nanoseeds
 */
#include "./candy_bar.h"

std::string trim(std::string str);

CandyBar::CandyBar() : name("\0"), weight(-1.0f), calories(-1) {
}

CandyBar::CandyBar(const char *n, double w, int32_t cal) : weight(w), calories(cal) {
    this->name = std::string(n);
    // use string's  ?
}

CandyBar::CandyBar(const std::string &n, double w, int32_t cal) : weight(w), calories(cal) {
    this->name = n;
    // use string's 拷贝构造函数
}

CandyBar::CandyBar(const CandyBar &s) : weight(s.weight), calories(s.calories) {
    this->name = s.name;
    // use string's 拷贝构造函数
}


CandyBar::CandyBar(CandyBar &&s) : weight(s.weight), calories(s.calories) {
    if (this != &s) {
        this->name = std::move(s.name);
        s.weight = -1.0f;
        s.calories = -1;
    }
}

CandyBar &CandyBar::operator=(CandyBar &&data) {
    if (this != &data) {
        this->weight = data.weight;
        this->calories = data.calories;
        this->name = std::move(data.name);
        data.weight = -1.0f;
        data.calories = -1;
    }
    return *this;
}

int32_t CandyBar::setCandyBar() {
    std::cout << "Enter brand name of a Candy bar: ";
    std::getline(std::cin, this->name);
    this->name = trim(this->name);
    std::cout << "Enter weight name of the candy bar: ";
    std::cin >> this->weight;
    std::cout << "Enter calories (an integer value) in the candy bar: ";
    std::cin >> this->calories;
    return 0;
}

void CandyBar::showCandyBar() {
    std::cout << "Brand: " << this->name << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Calorie: " << this->calories << std::endl;
}

CandyBar get_a_candyBar() {
    CandyBar will_return("123", 45.0f, 7);
    return will_return;
}

std::string trim(std::string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
