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

class scan_disk final : public disk_base {
public:
    scan_disk(size_t S, size_t M, size_t N, vector<size_t> requests) : disk_base(S, M, N, std::move(requests)) {
        vector<size_t> sorts{this->requests};
        for (const auto i: std::array<size_t, 3>{S, 1, M}) {
            sorts.push_back(i);
        }
        std::sort(std::begin(sorts), std::end(sorts), std::less<>());
        const auto range = std::equal_range(std::begin(sorts), std::end(sorts), S);
        for (auto left{range.first}; left != std::begin(sorts); --left) {
            this->steps.push_back(*left);
        }
        this->steps.push_back(*std::begin(sorts));
        for (auto left{range.first + 1}; left != std::end(sorts); ++left) {
            this->steps.push_back(*left);
        }
        for (size_t i{1}, size{this->steps.size()}; i < size; ++i) {
            this->distance += std::max(this->steps[i], this->steps[i - 1]) -
                              std::min(this->steps[i], this->steps[i - 1]);
        }
    };

    [[nodiscard]] const char *name() const override {
        return "Scan"; // 这个没缩写
    }
};

static constexpr const std::array<std::tuple<const char *const, const char *const, const char *const>, 4> pairs{
        std::tuple<const char *const, const char *const, const char *const>
                {"01.data.in", "scan/01.data.out", "scan/01.test.out"},
        std::tuple<const char *const, const char *const, const char *const>
                {"02.data.in", "scan/02.data.out", "scan/02.test.out"},
        std::tuple<const char *const, const char *const, const char *const>
                {"03.data.in", "scan/03.data.out", "scan/03.test.out"},
        std::tuple<const char *const, const char *const, const char *const>
                {"04.data.in", "scan/04.data.out", "scan/04.test.out"}
};

TEST_CASE("scan test sample") {
    for (const auto &[stdInput, stdOutput, testOutput]: pairs) {
        {
            const CS203_redirect cr{stdInput, testOutput};
            const auto input = inputs::read_input();
            const auto disk = std::make_unique<scan_disk>(input.S, input.M, input.N, input.requests);
            disk->output();
        }
        CHECK(compareFiles(stdOutput, testOutput));
    }
}


}
#endif