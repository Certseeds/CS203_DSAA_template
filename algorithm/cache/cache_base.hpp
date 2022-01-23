/*
MIT License

CS203_DSAA_template

Copyright (C) 2022 nanoseeds

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP


#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace cache {
class cache_base : protected nonCopyMoveAble {
protected:
    const size_t cache_size;
public:
    explicit cache_base(size_t x = 0) : cache_size(x) {};

    virtual bool exists(size_t value) const = 0;

    virtual bool read(size_t value) = 0;
};
}
struct inputs {
    const size_t cacheSize{};
    const size_t queryNumbers{};
    const vector<int32_t> querys;

    inputs(size_t cacheSize, size_t queryNumbers, vector<int32_t> querys) :
            cacheSize(cacheSize), queryNumbers(queryNumbers), querys(std::move(querys)) {}

    static inputs read_input() {
        size_t cache_size{0};
        size_t query_numbers{0};
        vector<int32_t> query_pages{};
        cin >> cache_size >> query_numbers;
        query_pages.reserve(query_numbers);
        int32_t temp_number;
        for (size_t i{0}; i < query_numbers; ++i) {
            cin >> temp_number;
            query_pages.push_back(temp_number);
        }
        return inputs{cache_size, query_numbers, query_pages};
    }
};

std::string getFilePath() noexcept {
    return "./../../../algorithm/cache/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
