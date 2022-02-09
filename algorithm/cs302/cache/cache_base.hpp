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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP


#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace cache {
class cache_base : protected nonCopyMoveAble {
protected:
    const size_t cache_size;
public:
    explicit cache_base(size_t x = 0) : cache_size(x) {};

    virtual bool exists(size_t value) const = 0;

    virtual bool read(size_t value) = 0;

    virtual ~cache_base() = default;
};
}
struct inputs {
    const size_t cacheSize{};
    const vector<int32_t> querys;

    inputs(size_t cacheSize, vector<int32_t> querys) :
            cacheSize(cacheSize), querys(std::move(querys)) {}

    static inputs read_input() {
        size_t cache_size{0};
        size_t query_numbers{0};
        vector<int32_t> query_pages{};
        cin >> cache_size >> query_numbers;
        query_pages.reserve(query_numbers);
        int32_t temp_number;
        for (size_t i{0}; i < query_numbers; ++i) {
            cin >> temp_number;
            query_pages.push_back(temp_number);
        }
        return inputs{cache_size, query_pages};
    }
};

std::string getFilePath() noexcept {
    return "./../../../../algorithm/cs302/cache/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
