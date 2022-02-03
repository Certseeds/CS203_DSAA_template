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

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <memory>
#include <list>
#include <queue>
#include <unordered_map>

namespace cache::fifo_sc {

const static vector<std::pair<size_t, string>> pairs{
        {5,     "4.data.in"},
        {2,     "sample.data.in"},
        {1177,  "1.data.in"},
        {11848, "2.data.in"},
        {82382, "3.data.in"},
        {5,     "5.data.in"},
        {6,     "6.data.in"},
        {1,     "7.data.in"},
};

namespace On {
class fifo_sc_cache final : private cache_base {
private:
    std::list<std::pair<size_t, bool>> que;
public:
    explicit fifo_sc_cache(size_t size) : cache_base(size) {}

    bool exists(size_t page) const override {
        return std::find_if(que.begin(), que.end(),
                            [page](std::pair<size_t, bool> pair) { return pair.first == page; }) != std::end(que);
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            const auto fst = std::find_if(que.begin(), que.end(),
                                          [page](std::pair<size_t, bool> pair) { return pair.first == page; });
            fst->second = true;
            return true;
        } else {
            if (que.size() == cache_size) {
                while (true) {
                    const auto[fst, snd] = que.front();
                    que.pop_front();
                    if (snd) {
                        que.emplace_back(fst, false);
                    } else {
                        break;
                    }
                }
            }
            que.emplace_back(page, false);
            return false;
        }
    }
};

TEST_CASE("fifo_sc test n") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<fifo_sc_cache>(input.cacheSize);
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
class fifo_sc_cache final : private cache_base {
private:
    std::queue<size_t, std::list<size_t>> que;
    std::unordered_map<size_t, bool> umap;
public:
    explicit fifo_sc_cache(size_t size) : cache_base(size) {}

    bool exists(size_t page) const override {
        return umap.find(page) != umap.end();
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            umap[page] = true;
            return true;
        } else {
            if (que.size() == cache_size) {
                while (true) {
                    const auto key = que.front();
                    que.pop();
                    const auto hadVisit = umap[key];
                    umap[key] = false;
                    if (hadVisit) {
                        que.push(key);
                    } else {
                        umap.erase(key);
                        break;
                    }
                }
            }
            que.push(page);
            umap[page] = false;
            return false;
        }
    }
};

TEST_CASE("fifo_sc test 1") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<fifo_sc_cache>(input.cacheSize);
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
