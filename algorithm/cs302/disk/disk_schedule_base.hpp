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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP


#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace disk_schedule {
class disk_base : protected nonCopyMoveAble {
protected:
    const size_t S, M, N;
    const vector<size_t> requests;
protected:
    vector<size_t> steps{};
    size_t distance{0};
public:
    explicit disk_base(size_t S, size_t M, size_t N, vector<size_t> requests) :
            S(S), M(M), N(N), requests(std::move(requests)) {};

    virtual const char * name() const = 0;

    void output() const {
        //std::cout << this->name() << '\n';
        for (auto iter = steps.cbegin(); iter != steps.cend() - 1; ++iter) {
            cout << *iter << ' ';
        }
        std::cout << steps.back() << '\n';
        std::cout << distance << '\n';
    }

    virtual ~ disk_base() = default;
};
}
struct inputs {
    const size_t S, M, N{};
    const vector<size_t> requests;

    inputs(size_t S, size_t M, size_t N, vector<size_t> requests) : S(S), M(M), N(N), requests(std::move(requests)) {}

    static inputs read_input() {
        size_t S, M, N{0};
        std::cin >> S >> M >> N;
        vector<size_t> requests(N);
        for (size_t i{0}; i < N; ++i) {
            std::cin >> requests[i];
        }
        return inputs{S, M, N, requests};
    }
};

std::string getFilePath() noexcept {
    return "./../../../../algorithm/cs302/disk/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP
