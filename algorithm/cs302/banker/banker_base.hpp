/*  CS203_DSAA_template
    Copyright (C) 2022  nanoseeds

    CS203_DSAA_template is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS203_DSAA_template is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_CS302_BANKER_BANKER_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_CS302_BANKER_BANKER_BASE_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>

namespace banker {
using std::string;
using std::vector;
enum class COMMAND_TYPE {
    NEW,
    REQUEST,
    TERMINATE,
};

struct COMMAND {
    const size_t process_id;
    const vector<size_t> resource;
    const COMMAND_TYPE command;

    COMMAND(const size_t processId, const vector<size_t> &resource, const banker::COMMAND_TYPE command)
            : process_id(processId), resource(resource), command(command) {}
};

struct inputs {
    const size_t resource_size;
    const vector<size_t> resource;
    const vector<COMMAND> commands;

    static inputs read_input() {
        static const std::unordered_map<string, COMMAND_TYPE> umap{{"new",       COMMAND_TYPE::NEW},
                                                                   {"request",   COMMAND_TYPE::REQUEST},
                                                                   {"terminate", COMMAND_TYPE::TERMINATE}};
        size_t resource_size;
        std::cin >> resource_size;
        vector<size_t> resource(resource_size, 0);
        for (auto &i: resource) {
            std::cin >> i;
        }
        size_t process_id{0};
        vector<COMMAND> commands;
        while (std::cin >> process_id) {
            string command_input;
            std::cin >> command_input;
            COMMAND_TYPE commandType = umap.at(command_input);
            vector<size_t> resource_vec{};
            switch (commandType) {
                case COMMAND_TYPE::TERMINATE: {
                    break;
                }
                case COMMAND_TYPE::NEW:
                case COMMAND_TYPE::REQUEST: {
                    resource_vec.resize(resource_size);
                    for (auto &i: resource_vec) {
                        std::cin >> i;
                    }
                }
            }
            commands.emplace_back(process_id, resource_vec, commandType);
        }
        return {resource_size, resource, commands};
    }
};


const auto files_tuple = [] {
    static constexpr const std::pair<int32_t, size_t> datas{0, 10};
    //static constexpr const std::pair<int32_t, size_t> datas{4, 5};
    std::vector<std::tuple<string, string, string>> files;
    for (size_t i{datas.first}; i < datas.second; ++i) {
        const auto str = '0' + std::to_string(i);
        files.emplace_back(str + ".data.in", str + ".data.out", str + ".test.out");
    }
    return files;
}();
}

std::string getFilePath() noexcept {
    return "./../../../../algorithm/cs302/banker/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_CS302_BANKER_BANKER_BASE_HPP
