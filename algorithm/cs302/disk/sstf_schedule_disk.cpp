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
#include "disk_schedule_base.hpp"
#include <array>
#include <algorithm>
#include <memory>
#include <unordered_set>

namespace disk_schedule::no {
using std::unordered_set;

class sstf_disk final : public disk_base {
public:
    sstf_disk(size_t S, size_t M, size_t N, vector<size_t> requests) : disk_base(S, M, N, std::move(requests)) {
        unordered_set<size_t> uset;
        for (const auto request: this->requests) {
            uset.insert(request);
        }
        size_t last_head{this->S};
        this->steps.push_back(last_head);
        for (size_t i{0}; i < this->N; ++i) {
            const auto min_p = std::min_element(
                    std::begin(uset), std::end(uset),
                    [last_head](const auto t1, const auto t2) {
                        return std::max(t1, last_head) - std::min(t1, last_head) <
                               std::max(t2, last_head) - std::min(t2, last_head);
                    }
            );
            this->distance += std::max(*min_p, last_head) - std::min(*min_p, last_head);
            last_head = *min_p;
            this->steps.push_back(last_head);
            uset.erase(min_p);
        }
    };

    [[nodiscard]] const char *name() const override {
        return "Shortest Seek Time First";
    }
};

static constexpr const std::array<std::tuple<const char *const, const char *const, const char *const>, 4> pairs{
        std::make_tuple("01.data.in", "sstf/01.data.out", "sstf/01.test.out"),
        std::make_tuple("02.data.in", "sstf/02.data.out", "sstf/02.test.out"),
        std::make_tuple("03.data.in", "sstf/03.data.out", "sstf/03.test.out"),
        std::make_tuple("04.data.in", "sstf/04.data.out", "sstf/04.test.out"),
};

TEST_CASE("sstf test sample") {
    for (const auto &[stdInput, stdOutput, testOutput]: pairs) {
        {
            const CS203_redirect cr{stdInput, testOutput};
            const auto input = inputs::read_input();
            const std::unique_ptr<disk_base> disk = std::make_unique<sstf_disk>(input.S, input.M, input.N,
                                                                                input.requests);
            disk->output();
        }
        CHECK(compareFiles(stdOutput, testOutput));
    }
}


}
#endif
