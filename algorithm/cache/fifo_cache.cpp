/*  CS203_DSAA_template
    Copyright (C) 2022  nafifoseeds

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

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <memory>
#include <queue>
#include <unordered_set>

namespace cache::fifo {

const static vector<std::pair<size_t, string>> pairs{
        {1,     "sample.data.in"},
        {1198,  "1.data.in"},
        {11854, "2.data.in"},
        {82363, "3.data.in"},
        {2,     "4.data.in"},
        {5,     "5.data.in"},
        {4,     "6.data.in"},
        {2,     "7.data.in"},
};

namespace On {
class fifo_cache final : private cache_base {
private:
    std::deque<size_t> que;
public:
    explicit fifo_cache(size_t size) : cache_base(size) {}

    bool exists(size_t page) const override {
        return std::find(que.begin(), que.end(), page) != std::end(que);
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            return true;
        } else {
            if (que.size() == cache_size) {
                que.pop_front();
            }
            que.push_back(page);
            return false;
        }
    }
};

TEST_CASE("fifo test n") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<fifo_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(result == hits);
    }
}
}

namespace O1 {
class fifo_cache final : private cache_base {
private:
    std::queue<size_t> que;
    std::unordered_set<size_t> uset;
public:
    explicit fifo_cache(size_t size) : cache_base(size) {}

    bool exists(size_t page) const override {
        return uset.count(page) != 0;
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            // the problem is that, nothing to do when cache hit
            return true;
        } else {
            if (que.size() == cache_size) {
                const auto last{que.front()};
                uset.erase(last);
                que.pop();
            }
            que.push(page);
            uset.insert(page);
            return false;
        }
    }
};

TEST_CASE("fifo test 1") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<fifo_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(result == hits);
    }
}
}

}
#endif
