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
 * @Date: 2020-04-19 21:00:12
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_01.hpp"

unordered_map<int32_t, vector<int32_t>> umap;

int32_t question1() {
    // student-number
    uint32_t number = 0;
    // sid to vector
    // randoms
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int32_t> year(range.first, range.second);
    std::uniform_int_distribution<int32_t> last(0, 9);
    std::uniform_int_distribution<int32_t> scores(0, 5);
    // read
    cout << "The Number of students" << endl;
    cin >> number;
    if (cin.fail()) {
        cout << "Bad input" << endl;
        return -1;
    }
    while (number != umap.size()) {
        // random produce until is enough
        int32_t id = year(e1);
        for (uint32_t j = 0; j < 4; ++j) {
            id = id * 10 + last(e1);
        }
        vector<int32_t> score(lab_number, 0);
        for (auto &j: score) {
            j = scores(e1);
        }
        umap[id] = score;
    }//output
    for (const auto &i: umap) {
        cout << i.first << ": ";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            cout << i.second[j] << ", ";
        }
        cout << i.second.back() << endl;
    }
    return 0;
}