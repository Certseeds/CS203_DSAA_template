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
 * @Date: 2020-04-20 08:50:41
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_05.hpp"

int32_t question5() {
    while (true) {
        std::cout << "<";
        // switch
        int32_t temp = recieve_input();
        // std::cout << temp << std::endl;
        switch (temp) {
            case exit_n: {
                std::cout << "exit" << std::endl;
                return 0;
            }
            case illegal: {
                std::cout << "Invalid command" << std::endl;
                break;
            }
            default: {
                std::cout << "command " << command[temp] << " recognized" << std::endl;
                break;
            }
        }
    }
    return 0;
}

int32_t recieve_input() {
    // recieve input and return order.
    std::string input;
    std::cin >> input;
    input = trim(input);
    input = str_lower(input);
    return std::distance(std::cbegin(command), std::find(std::cbegin(command), std::cend(command), input));
}

// 给分的时候,虽然没写要处理大小写,但是还是扣分了.
// PS: argue回来了
std::string str_lower(std::string str) {
    for (auto &item: str) {
        if (item >= 'A' && item <= 'Z') {
            item = item - ('A' - 'a');
        }
    }
    return str;
}

std::string trim(std::string str) {
    // delete spaces
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}