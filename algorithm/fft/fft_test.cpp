/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-05-13 20:29:44
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2021  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "fft.hpp"
#include <catch_main.hpp>

namespace fft {
    using Catch::Matchers::Equals;
    using Catch::Matchers::UnorderedEquals;
    using Catch::Matchers::Contains;

    TEST_CASE("basic -2", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(21ull)};
        const vector<int32_t> vec2{num_to_vec(43ull)};
        const vector<int32_t> result{num_to_vec(903ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("basic -1", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(4211ull)};
        const vector<int32_t> vec2{num_to_vec(3655ull)};
        const vector<int32_t> result{num_to_vec(15391205ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("basic 0", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(21ull)};
        const vector<int32_t> vec2{num_to_vec(35ull)};
        const vector<int32_t> result{num_to_vec(735ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("basic 1", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(123ull)};
        const vector<int32_t> vec2{num_to_vec(456ull)};
        const vector<int32_t> result{num_to_vec(56088ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("basic 2", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(114514ull)};
        const vector<int32_t> vec2{num_to_vec(1919810ull)};
        const vector<int32_t> result{num_to_vec(219845122340ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("basic 3", "[algorithm fft]") {
        const vector<int32_t> vec1{num_to_vec(201037ull)};
        const vector<int32_t> vec2{num_to_vec(20210513ull)};
        const vector<int32_t> result{num_to_vec(4063060901981ull)};
        CHECK_THAT(multiply(vec1, vec2), Equals(result));
    }

    TEST_CASE("extend check 0", "[algorithm fft]") {
        vector<int32_t> vec1{1};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{1}));
    }

    TEST_CASE("extend check 1", "[algorithm fft]") {
        vector<int32_t> vec1{1, 2};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2}));
    }

    TEST_CASE("extend check 2", "[algorithm fft]") {
        vector<int32_t> vec1{};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{}));
    }

    TEST_CASE("extend check 3", "[algorithm fft]") {
        vector<int32_t> vec1{1, 2, 3};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2, 3, 0}));
    }

    TEST_CASE("extend check 4", "[algorithm fft]") {
        vector<int32_t> vec1{1, 2, 3, 4};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2, 3, 4}));
    }

    TEST_CASE("extend check 5", "[algorithm fft]") {
        vector<int32_t> vec1{1,2,3,4,5};
        extend(vec1);
        CHECK_THAT(vec1, Equals(vector<int32_t>{1,2,3,4,5,0,0,0}));
    }
}