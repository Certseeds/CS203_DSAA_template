// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_535_test.hpp"
#include <unordered_map>

namespace leetcode_535 {
using std::unordered_map;

class c1 : public base {
public:
    [[nodiscard]] string encode(const string longUrl) override {
        return longUrl;
    }

    [[nodiscard]] string decode(const string shortUrl) override {
        return shortUrl;
    }

    static base *getPointer() {
        static base *const pointer = new c1{};
        return pointer;
    }
};


base *leetcode_535::getObject1() {
    return c1::getPointer();
}
}