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
#ifdef CS203_DSAA_TEST_MACRO

#include "banker_base.hpp"
#include <class_helper/nonable.hpp>

namespace banker {
using std::unordered_map;

struct process {
    const size_t process_id{};
    vector<size_t> alloc_resource;
    vector<size_t> needed_resource;

    process(size_t id, const vector<size_t> &resource) : process_id(id),
                                                         alloc_resource(vector<size_t>(resource.size(), 0)),
                                                         needed_resource(resource) {};
};

class bankerAlgo : private nonCopyMoveAble {
    const size_t resource_size;
    const vector<size_t> max_resources;
    vector<size_t> resources;
    std::unordered_map<size_t, process> umap{};


    bool invokeNew(const COMMAND &command) {
        if (umap.find(command.process_id) != std::end(umap)) {
            return false;
        }
        for (size_t i{0}; i < this->resource_size; ++i) {
            if (this->max_resources[i] < command.resource[i]) {
                return false;
            }
        }
        umap.emplace(command.process_id, process(command.process_id, command.resource));
        return true;
    }

    static void do_request(const COMMAND &command, vector<size_t> &resource, unordered_map<size_t, process> &umap) {
        const auto id{command.process_id};
        for (size_t i{0}, size{resource.size()}; i < size; ++i) {
            umap.at(id).alloc_resource[i] += command.resource[i];
            umap.at(id).needed_resource[i] -= command.resource[i];
            resource[i] -= command.resource[i];
        }
    }

    bool invokeRequest(const COMMAND &command) {
        if (umap.find(command.process_id) == std::end(umap)) {
            return false;
        }
        const auto &process = umap.at(command.process_id);
        vector<size_t> copyResource = this->resources;
        std::unordered_map<size_t, banker::process> copyUmap = umap;
        for (size_t i{0}; i < resource_size; ++i) {
            if (command.resource[i] > std::min(process.needed_resource[i], copyResource[i])) {
                return false;
            }
        }
        do_request(command, copyResource, copyUmap);

        for (size_t i{0}, size{copyUmap.size()}; i < size; ++i) {
            bool jump_out{false};
            for (const auto &[item_first, item_second]: copyUmap) {
                bool jump_in{true};
                for (size_t j{0}; j < this->resource_size; ++j) {
                    if (item_second.needed_resource[j] > copyResource[j]) {
                        jump_in = false;
                        break;
                    }
                }
                if (jump_in) {
                    jump_out = true;
                    for (size_t j{0}; j < this->resource_size; ++j) {
                        copyResource[j] += item_second.alloc_resource[j];
                    }
                    copyUmap.erase(item_first);
                    break;
                }
            }
            if (!jump_out) {
                return false;
            }
        }
        do_request(command, this->resources, this->umap);
        return true;
    }

    bool invokeTerminate(const COMMAND &command) {
        if (umap.find(command.process_id) == std::end(umap)) {
            return false;
        }
        const auto &process_in_map = umap.at(command.process_id);
        for (size_t i{0}; i < resource_size; ++i) {
            this->resources[i] += process_in_map.alloc_resource[i];
        }
        umap.erase(command.process_id);
        return true;
    }

public:
    bankerAlgo(const size_t resourceSize, const vector<size_t> &resources) : resource_size(resourceSize),
                                                                             max_resources(resources),
                                                                             resources(resources) {}

    bool invoke(const COMMAND &command) {
        switch (command.command) {
            case COMMAND_TYPE::NEW:
                return this->invokeNew(command);
            case COMMAND_TYPE::REQUEST:
                return this->invokeRequest(command);
            case COMMAND_TYPE::TERMINATE:
                return this->invokeTerminate(command);
        }
    }

    static void output(const bool result) {
        static constexpr const std::array<const char *const, 2> results{"NOT OK", "OK"};
        std::cout << results[result] << '\n';
    }
};


TEST_CASE("banker test sample") {
    for (const auto&[stdInput, stdOutput, testOutput]: files_tuple) {
        {
            const CS203_redirect cr{stdInput, testOutput};
            const auto input = inputs::read_input();
            bankerAlgo algorithm{input.resource_size, input.resource};
            for (const auto &command: input.commands) {
                const auto result = algorithm.invoke(command);
                bankerAlgo::output(result);
            }
        }
        CHECK(compareFiles(stdOutput, testOutput));
    }
}

}

#endif
