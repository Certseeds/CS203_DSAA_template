// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag HashMap
//@Tag 哈希表
//@Tag Trie
//@Tag 字典树
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_TEST_HPP

#include <catch_main.hpp>
#include <tree/trie.hpp>
#include <memory>

namespace leetcode_208 {
struct leetcode_208 {
    using trie = trie::trie;
    using trie2 = trieR::trie;
};

TEST_CASE("1 [test_208]", "[test_208]") {
    const auto leetcode_208_tire = std::make_unique<leetcode_208::trie>();
    leetcode_208_tire->insert("apple");
    leetcode_208_tire->insert("apple");
    CHECK(leetcode_208_tire->search("apple"));
    CHECK_FALSE(leetcode_208_tire->search("app"));
    CHECK(leetcode_208_tire->startsWith("app"));
    leetcode_208_tire->insert("app");
    CHECK(leetcode_208_tire->search("app"));
}

TEST_CASE("2 [test_208]", "[test_208]") {
    const auto leetcode_208_tire = std::make_unique<leetcode_208::trie>();
    leetcode_208_tire->insert("hello");
    CHECK_FALSE(leetcode_208_tire->search("hell"));
    CHECK_FALSE(leetcode_208_tire->search("helloa"));
    CHECK(leetcode_208_tire->search("hello"));
    CHECK(leetcode_208_tire->startsWith("hell"));
    CHECK_FALSE(leetcode_208_tire->startsWith("helloa"));
    CHECK(leetcode_208_tire->startsWith("hello"));
}

TEST_CASE("1-2 [test_208]", "[test_208]") {
    const auto leetcode_208_tire2 = std::make_unique<leetcode_208::trie2>();
    leetcode_208_tire2->insert("apple");
    CHECK(leetcode_208_tire2->search("apple"));
    CHECK_FALSE(leetcode_208_tire2->search("app"));
    CHECK(leetcode_208_tire2->startsWith("app"));
    leetcode_208_tire2->insert("app");
    CHECK(leetcode_208_tire2->search("app"));
}

TEST_CASE("2-2 [test_208]", "[test_208]") {
    const auto leetcode_208_tire2 = std::make_unique<leetcode_208::trie2>();
    leetcode_208_tire2->insert("hello");
    CHECK_FALSE(leetcode_208_tire2->search("hell"));
    CHECK_FALSE(leetcode_208_tire2->search("helloa"));
    CHECK(leetcode_208_tire2->search("hello"));
    CHECK(leetcode_208_tire2->startsWith("hell"));
    CHECK_FALSE(leetcode_208_tire2->startsWith("helloa"));
    CHECK(leetcode_208_tire2->startsWith("hello"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_TEST_HPP
