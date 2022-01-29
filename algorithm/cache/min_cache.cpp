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
#include <queue>
#include <unordered_set>
#include <vector>

namespace cache::min {

const static vector<std::pair<size_t, string>> pairs{
        {2,     "sample.data.in"},
        {4240,  "1.data.in"},
        {43265, "2.data.in"},
        {88583, "3.data.in"},
        {7,     "4.data.in"},
        {5,     "5.data.in"},
        {9,     "6.data.in"},
        {3,     "7.data.in"},
};

/**
 * 这是个需要"预知未来"的算法
 * 平均O(n)算不错的了
 * */
namespace On {
using std::priority_queue, std::unordered_set, std::vector;

class min_cache final : private cache_base {
private:
    struct pn final {
        size_t page, next;
    };
    static constexpr const auto cmp = [](const pn v1, const pn v2) { return v1.next > v2.next; };
private:
    const vector<size_t> predict;
    size_t position{0};
    std::set<pn, decltype(cmp)> uset{cmp}; // 没想到set充当优先队列这么优秀
private:
    /**
     * Example
     * [1,2,3,4,5,2] && position 1, 所以从2开始搜索,找到下一个2,即第六个位置-5
     */
    size_t getNext(size_t page) {
        position += 1;
        for (size_t i{position}, size{predict.size()}; i < size; i++) {
            if (predict[i] == page) {
                return i;
            }
        }
        return std::numeric_limits<size_t>::max();
    }

public:
    explicit min_cache(size_t size, vector<size_t> pri) : cache_base(size), predict(std::move(pri)) {}

    [[nodiscard]] bool exists(size_t page) const override {
        return std::end(uset) !=
               std::find_if(uset.begin(), uset.end(), [page](const auto search) { return search.page == page; });
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            const auto iter = std::find_if(uset.begin(), uset.end(),
                                           [page](const auto search) { return search.page == page; });
            uset.erase(iter);
            const auto next{this->getNext(page)};
            uset.insert({page, next});
            return true;
        } else {
            if (uset.size() == cache_size) {
                const auto top_iter = uset.cbegin();
                uset.erase(top_iter);
            }
            const auto next{this->getNext(page)};
            uset.insert({page, next});
            return false;
        }
    }
};

TEST_CASE("min test 1") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto inputAll = [&input] {
            vector<size_t> vec{};
            for (const auto ori: input.querys) {
                vec.push_back(ori);
            }
            return vec;
        }();
        const auto cache = std::make_unique<min_cache>(input.cacheSize, inputAll);
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
