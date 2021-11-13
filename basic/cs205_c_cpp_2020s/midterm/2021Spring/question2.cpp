/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-16 00:50:01
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:24:40
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
#include <iostream>
#include <tuple>
#include <unordered_map>
// 没找到原题
namespace question2 {
using namespace std;
using input_type = std::tuple<unordered_map<int32_t, int32_t>, int32_t, int32_t>;
using output_type = int32_t;

input_type readNumber() {
    size_t n{0};
    int32_t x{0}, y{0}, key{0};
    unordered_map<int32_t, int32_t> umap;
    std::cin >> n >> x >> y;
    for (size_t i{0}; i < n; ++i) {
        std::cin >> key;
        umap[key]++;
    }
    return std::make_tuple(umap, x, y);
}

int32_t count(input_type input) {
    static constexpr const int32_t MAX_SCORE{100};
    //时间复杂度O(MAX_SCORE^2 + n)
    const auto isOK = [&](int32_t value) {
        int32_t sum1{0}, sum2{0};
        for (const auto&[k, v]: std::get<0>(input)) {
            if (k > value) {
                sum1 += v;
            } else {
                sum2 += v;
            }
        }
        return std::get<1>(input) <= sum1 && sum1 <= std::get<2>(input) &&
               std::get<1>(input) <= sum2 && sum2 <= std::get<2>(input);
    };
    for (int32_t i{0}; i < MAX_SCORE; ++i) {
        if (isOK(i)) {
            return i;
        }
    }
    return 0;
}

void output(output_type num) {
    std::cout << num << std::endl;
}

int main() {
    const auto &input{readNumber()};
    const auto &will_return{count(input)};
    output(will_return);
    return 0;
}
}
#ifndef CS205_C_CPP_MIDTERM_2021SPRING

int main() {
    return question2::main();
}

#endif