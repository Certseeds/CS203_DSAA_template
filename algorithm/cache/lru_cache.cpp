/*  CS203_DSAA_template
    Copyright (C) 2022  nanoseeds

    CS302_OS is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS302_OS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <list>
#include <unordered_set>
#include <memory>

std::string getFilePath() noexcept {
    return "./../../../algorithm/cache/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
namespace cache::lru {
class lru_cache final : public cache_base {
private:
    std::list<size_t> lru;
    std::unordered_set<size_t> uset;
public:
    explicit lru_cache(size_t size = 0) : cache_base(size) {}

    bool exists(size_t value) const override {
        return uset.find(value) != uset.end();
    }

    bool insert(size_t value) override {
        const auto result = std::find(std::begin(lru), std::end(lru), value);
        const auto judge = (result != std::end(lru));
        if (judge) {
            lru.erase(result);
            lru.push_front(value);
        } else {
            if (lru.size() == cache_size) {
                lru.pop_back();
                uset.erase(lru.back());
            }
            lru.push_front(value);
            uset.insert(value);
        }
        return judge;
    }
};

TEST_CASE("lru test sample") {
    const vector<std::pair<size_t, string>> pairs{
            {1,     "sample.data.in"},
            {1176,  "1.data.in"},
            {11847, "2.data.in"},
            {82394, "3.data.in"},
            {4,     "4.data.in"},
            {3,     "5.data.in"},
            {5,     "6.data.in"},
            {1,     "7.data.in"},
    };
    for (const auto&[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<lru_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->insert(iter);
            hits += exist;
        }
        CHECK(result == hits);
    }
}

}
#endif
