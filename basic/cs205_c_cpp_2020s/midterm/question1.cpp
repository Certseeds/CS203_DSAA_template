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
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-16 14:06:45
 * @LastEditors  : nanoseeds
 */
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
constexpr int32_t buffer_size = 1024;

int32_t evaluate(const char *s, int32_t k);

int main() {
    char recieve_string[buffer_size];
    int32_t frequency;
    cin.getline(recieve_string, buffer_size);
    std::cin >> frequency;
    std::cout << evaluate(recieve_string, frequency) << std::endl;
    return 0;
}

int32_t evaluate(const char *s, const int32_t k) {
    string str(s);
    unordered_map<string, int32_t> umap;
    vector <int32_t> positions;
    positions.push_back(-1);
    for (uint32_t i = 0; i < str.size(); ++i) {
        if (' ' == s[i]) {
            positions.push_back(i);
        }
    }
    positions.push_back(str.size());
    for (uint32_t i = 0; i < positions.size() - 1; ++i) {
        int32_t temp_size = positions[i + 1] - positions[i];
        string test2 = str.substr(positions[i] + 1, temp_size - 1);
        umap[test2]++;
        if (umap[str.substr(positions[i] + 1, temp_size - 1)] >= k) {
            return true;
        }
    }
    return false;
}