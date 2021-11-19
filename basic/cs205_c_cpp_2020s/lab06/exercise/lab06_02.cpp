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
 * @Date: 2020-03-26 22:02:50
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <cstring>

static constexpr const int32_t lab06_02_max_length = 1024;

int main() {
    std::cout << "Enter words (q to quit): ";
    std::cout.flush();
    int32_t nVowel = 0;
    int32_t nConsonant = 0;
    int32_t nOther = 0;
    char word[lab06_02_max_length + 1];
    while (std::cin >> word) {
        if (isalpha(word[0])) {
            if (strlen(word) == 1 && word[0] == 'q') {
                break;
            }
            char x = tolower(word[0]);
            switch (x) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': {
                    nVowel++;
                    break;
                }
                default: {
                    nConsonant++;
                    break;
                }
            }
        } else {
            nOther++;
        };
    }
    std::cout << nVowel << " words begining with vowels" << std::endl
              << nConsonant << " words begining with consonants" << std::endl
              << nOther << " others" << std::endl;
    return 0;
}