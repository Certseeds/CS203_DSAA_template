/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.RRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WA

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <catch_main.hpp>
#include "dijistra.hpp"

namespace graph {
namespace dijistra {
using Catch::Matchers::Equals;
// 无负值最短路径
// Dijkstra
TEST_CASE("1 [test graph dijistra]", "[test graph dijistra]") {
    const auto obj = graphlist(
            {{{7, 13, 53}, {10, 5, 86}, {5, 14, 45}, {5, 10, 49}, {5, 6, 77}, {12, 9, 95}, {6, 10, 75}, {7, 4, 61},
              {8, 5, 2}, {10, 1, 45}, {11, 14, 19}, {9, 15, 15}, {6, 4, 95}, {6, 1, 4}, {8, 12, 29}, {1, 9, 15},
              {10, 9, 81}, {13, 5, 13}, {9, 13, 85}, {2, 8, 45}, {7, 8, 11}, {7, 3, 63}, {2, 11, 60}, {2, 5, 59},
              {6, 12, 35}, {14, 11, 69}, {10, 4, 96}, {10, 8, 33}, {11, 15, 79}, {3, 14, 42}, {6, 2, 53}, {1, 11, 99},
              {11, 1, 27}, {8, 13, 75}, {14, 8, 45}, {12, 6, 99}, {7, 14, 13}, {14, 13, 46}, {4, 8, 83}, {14, 15, 28},
              {6, 8, 79}, {10, 6, 2}, {2, 1, 85}, {14, 12, 37}, {5, 2, 22}, {9, 10, 97}, {4, 5, 93}, {6, 7, 3},
              {13, 3, 19}, {12, 1, 34}, {7, 15, 37}, {12, 14, 66}, {4, 9, 6}, {3, 9, 45}, {15, 6, 39}, {8, 3, 92},
              {12, 7, 29}, {9, 6, 24}, {15, 5, 71}, {2, 13, 99}, {9, 1, 58}, {9, 3, 61}, {3, 2, 83}, {2, 15, 52},
              {8, 6, 14}, {3, 13, 62}, {3, 10, 86}, {4, 7, 58}, {8, 7, 40}, {14, 7, 67}, {15, 9, 40}, {7, 6, 6},
              {14, 5, 22}, {11, 6, 20}, {4, 12, 29}, {7, 12, 18}, {1, 2, 16}, {7, 11, 20}, {1, 5, 64}, {1, 7, 27},
              {1, 10, 88}, {1, 14, 48}, {15, 3, 94}, {3, 7, 21}, {5, 15, 43}, {5, 13, 23}, {15, 10, 54}, {1, 8, 36},
              {3, 8, 95}, {2, 7, 94}, {9, 5, 42}, {4, 3, 90}, {11, 7, 74}, {11, 3, 16}, {3, 11, 10}, {8, 11, 29},
              {10, 13, 79}, {9, 8, 75}, {14, 10, 13}, {3, 5, 81}, {8, 14, 45}, {13, 1, 85}, {5, 4, 78}, {11, 5, 4},
              {12, 8, 43}, {2, 6, 99}, {12, 13, 72}, {10, 3, 8}, {9, 4, 62}, {7, 9, 0}, {15, 7, 50}, {12, 2, 20},
              {1, 4, 0}, {10, 12, 48}, {6, 9, 22}, {11, 8, 52}, {13, 7, 29}, {4, 10, 45}, {6, 15, 6}, {9, 11, 84},
              {3, 15, 85}, {15, 11, 76}, {8, 9, 72}, {8, 15, 46}, {13, 6, 32}, {2, 12, 99}, {11, 10, 15}, {2, 3, 36},
              {15, 12, 46}, {12, 15, 70}, {5, 3, 21}, {14, 4, 42}, {8, 4, 64}, {1, 6, 90}, {13, 11, 73}, {15, 14, 84},
              {9, 2, 98}, {7, 2, 98}, {1, 12, 28}, {4, 15, 3}, {2, 9, 70}, {4, 14, 95}, {11, 12, 80}, {14, 3, 89},
              {8, 2, 49}, {4, 1, 25}, {8, 1, 68}, {5, 1, 27}, {9, 7, 97}, {13, 2, 44}, {5, 7, 71}, {10, 11, 89},
              {3, 12, 67}, {14, 1, 77}, {10, 15, 92}, {2, 4, 79}, {4, 6, 25}, {5, 9, 81}, {6, 14, 97}, {11, 4, 96},
              {9, 12, 43}, {13, 10, 7}, {10, 7, 19}, {15, 13, 76}, {7, 5, 16}, {13, 14, 45}, {12, 3, 59}, {13, 9, 60},
              {6, 13, 62}, {13, 4, 42}, {5, 12, 3}, {4, 11, 79}, {7, 1, 58}, {14, 6, 64}, {12, 11, 5}, {2, 10, 92},
              {10, 2, 45}, {7, 10, 90}, {13, 15, 56}, {1, 3, 0}, {4, 2, 53}, {5, 11, 25}, {15, 4, 39}, {12, 5, 34},
              {6, 5, 70}, {1, 15, 23}, {15, 8, 40}, {5, 8, 11}, {2, 14, 57}, {4, 13, 19}, {15, 1, 18}, {12, 4, 95},
              {1, 13, 22}, {11, 9, 74}, {14, 9, 86}, {11, 13, 46}, {8, 10, 10}, {14, 2, 43}, {3, 4, 91}, {15, 2, 66},
              {10, 14, 32}, {13, 8, 67}, {6, 3, 2}, {9, 14, 3}, {6, 11, 71}, {11, 2, 67}, {3, 1, 65}, {13, 12, 0},
              {3, 6, 27}, {12, 10, 77}}},
            15);
    CHECK_THAT(obj.dijkstra(2),
               Equals(vector<int32_t>{61, 0, 36, 61, 47, 57, 57, 45, 57, 55, 46, 50, 70, 57, 52}));
}

TEST_CASE("2 [test graph dijistra]", "[test graph dijistra]") {
    const auto obj = graphlist({{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}}, 4);
    CHECK_THAT(obj.dijkstra(2), Equals(vector<int32_t>{1, 0, 1, 2}));
}

TEST_CASE("3 [test graph dijistra]", "[test graph dijistra]") {
    const auto obj = graphlist({{{1, 2, 1}}}, 2);
    CHECK_THAT(obj.dijkstra(1), Equals(vector<int32_t>{0, 1}));
    CHECK_THAT(obj.dijkstra(2), Equals(vector<int32_t>{0x3f3f3f3f, 0}));
}
}
}