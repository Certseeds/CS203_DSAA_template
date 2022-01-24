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

namespace cache::no {

class no_cache final : private cache_base {
public:
    explicit no_cache(size_t size = 0) : cache_base(0) {}

    bool exists(size_t value) const override { return false; }

    bool read(size_t value) override { return false; }
};
const vector<string> pairs{
        "sample.data.in",
        "1.data.in",
        "2.data.in",
        "3.data.in",
        "4.data.in",
        "5.data.in",
        "6.data.in",
        "7.data.in",
};
TEST_CASE("no test sample") {
    for (const auto &file_name: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<no_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(0 == hits);
    }
}

}
#endif
