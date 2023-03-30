// SPDX-License-Identifier: AGPL-3.0-or-later
/* CS205_C_CPP
   Copyright (C) 2020-2023 nanoseeds
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
