/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
//@Tag string
//@Tag 字符串
//@Tag HashMap
//@Tag 哈希表
//@Tag Trie
//@Tag 字典树
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_HPP

#include <catch_main.hpp>

#include <array>
#include <string>
#include <unordered_set>

namespace leetcode_208 {
using std::endl;
using std::string;
using std::unordered_set;

struct leetcode_208 {
    struct TrieTemplate {
        TrieTemplate() = default;

        TrieTemplate(const TrieTemplate &) = delete;

        TrieTemplate(TrieTemplate &&) = delete;

        TrieTemplate &operator=(const TrieTemplate &) = delete;

        TrieTemplate &operator=(TrieTemplate &&) = delete;

        virtual void insert(const string &) {}

        virtual bool search(const string &) { return false; }

        virtual bool startsWith(const string &) { return false; }
    };

    struct trie : public TrieTemplate {
    private:
        unordered_set<string> uset{};
    public:
        trie() = default;

        void insert(const string &word) override;

        bool search(const string &word) override;

        bool startsWith(const string &prefix) override;
    };

    struct trie2 : public TrieTemplate {
    private:
        static constexpr const size_t array_size{26};

        class Node final {
        public:
            uint8_t self, isfinish;
            std::array<Node *, array_size> sons{nullptr};

            explicit Node(uint8_t self_, uint8_t finish) : self(self_), isfinish(finish) {
            }

            ~Node() {
                for (size_t i{0}; i < array_size; i++) {
                    delete sons[i];
                    sons[i] = nullptr;
                }
            }
        };

        std::array<Node *, array_size> sons{nullptr};
    public:
        trie2() = default;

        ~trie2() {
            for (size_t i{0}; i < array_size; i++) {
                delete sons[i];
                sons[i] = nullptr;
            }
        }

        void insert(const string &word) override;

        bool search(const string &word) override;

        bool startsWith(const string &prefix) override;
    };
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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_208_HPP
