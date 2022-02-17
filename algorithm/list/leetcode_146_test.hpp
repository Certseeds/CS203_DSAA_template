/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>

namespace leetcode_146 {

class LRUCache {
protected:
    const size_t size;
public:
    explicit LRUCache(int32_t capacity) : size(capacity) {}

    virtual int32_t get(int32_t key) = 0;

    virtual void put(int32_t key, int32_t value) = 0;

    virtual ~LRUCache() = default;
};


struct leetcode_146 {
    static std::unique_ptr<LRUCache> get(int32_t cap);
};

TEST_CASE("fst [test_146]", "[test_146]") {
    const auto ptr = leetcode_146::get(2);
    ptr->put(1, 1);
    ptr->put(2, 2);
    CHECK(1 == ptr->get(1));
    ptr->put(3, 3);
    CHECK(-1 == ptr->get(2));
    ptr->put(4, 4);
    CHECK(-1 == ptr->get(1));
    CHECK(3 == ptr->get(3));
    CHECK(4 == ptr->get(4));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP
