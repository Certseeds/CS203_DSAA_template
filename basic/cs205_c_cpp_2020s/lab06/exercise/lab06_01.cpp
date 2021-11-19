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
 * @Date: 2020-03-26 21:28:07
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <cstring>

static constexpr const int32_t lab06_01_max_length = 1024;

int main() {
    char beta;
    char output[lab06_01_max_length];
    memset(output, '\0', lab06_01_max_length * sizeof(char));
    std::cout << "Enter any alphabet: ";
    std::cin >> beta;
    if (isalpha(beta)) {
        switch (tolower(beta)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {
                sprintf(output, "Vowel");
                break;
            }
            default: {
                sprintf(output, "Consonant");
                break;
            }
        }
    } else {
        sprintf(output, "Error! please input vowel or consonant characters");
    }
    std::cout << output << std::endl;
    return 0;
}