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
#include <array>
#include <memory>
#include <unordered_map>

/**
 * 当刚入场的page,visit被置为false时会与被置为true有明显不一致
 * clock默认为true
 * fifo_sc则不修改,默认为false
 * */
namespace cache::clock {
using std::array;
static constexpr const auto init = true;
namespace initFalse {
static constexpr const std::array<const std::pair<size_t, const char *const>, 8> pairs{
        {
                {5, "4.data.in"},
                {2, "sample.data.in"},
                {1177, "1.data.in"},
                {11848, "2.data.in"},
                {82382, "3.data.in"},
                {5, "5.data.in"},
                {6, "6.data.in"},
                {1, "7.data.in"},
        }};
}
namespace initTrue {
static constexpr const std::array<const std::pair<size_t, const char *const>, 8> pairs{
        {
                {2, "4.data.in"},
                {1, "sample.data.in"},
                {1193, "1.data.in"},
                {11826, "2.data.in"},
                {82382, "3.data.in"},
                {5, "5.data.in"},
                {4, "6.data.in"},
                {2, "7.data.in"},
        }};
}
namespace On {
class clock_cache final : public cache_base {
private:
    std::vector<std::pair<size_t, bool>> que;// 双链表(大小固定)的和vector没区别
    size_t pointer = 0;
public:
    explicit clock_cache(size_t size) : cache_base(size),
                                        que(vector<std::pair<size_t, bool>>
                                                    (size, {std::numeric_limits<size_t>::max(), false})) {
        CHECK(size != 0);
    }

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
            while (true) {
                const auto[fst, snd] = que[pointer % cache_size];
                que[pointer % cache_size].second = false;
                if (snd) {
                    pointer++;
                } else {
                    que[pointer % cache_size].first = std::numeric_limits<size_t>::max();
                    break;
                }
            }
            que[pointer % cache_size].first = page;
            que[pointer % cache_size].second = init;
            pointer++;
            return false;
        }
    }
};

TEST_CASE("clock test n") {
    for (const auto &[result, file_name]: init ? initTrue::pairs : initFalse::pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<clock_cache>(input.cacheSize);
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
class clock_cache final : public cache_base {
private:
    std::vector<size_t> que;
    std::unordered_map<size_t, bool> umap;
    size_t pointer = 0;
public:
    explicit clock_cache(size_t size) : cache_base(size),
                                        que(vector<size_t>(size, std::numeric_limits<size_t>::max())) {
        CHECK(size != 0);
    }

    bool exists(size_t page) const override {
        return umap.find(page) != umap.end();
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            umap[page] = true;
            return true;
        } else {
            for (;; pointer = pointer % cache_size) {
                const auto key = que[pointer % cache_size];
                const auto hadVisit = umap[key];
                umap[key] = false;
                if (hadVisit) {
                    pointer++;
                } else {
                    que[pointer % cache_size] = std::numeric_limits<size_t>::max();
                    umap.erase(key);
                    break;
                }
            }
            que[pointer % cache_size] = page;
            umap[page] = init;
            pointer++;
            return false;
        }
    }
};

TEST_CASE("clock test 1") {
    for (const auto &[result, file_name]: init ? initTrue::pairs : initFalse::pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const std::unique_ptr<cache_base> cache = std::make_unique<clock_cache>(input.cacheSize);
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
