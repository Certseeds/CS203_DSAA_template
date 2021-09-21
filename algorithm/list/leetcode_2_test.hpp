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
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_HPP

#include <catch_main.hpp>
#include <unordered_map>
#include <ListNode.hpp>

namespace leetcode_2 {
using LISTNODE::ListNode;
using std::unordered_map;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_2 {
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};


TEST_CASE("basic tests [test 2]", "[test 2]") {
    vector<ListNode *> vec1 = ListNode::numToList(vector<int>{2, 4, 3});
    vector<ListNode *> vec2 = ListNode::numToList(vector<int>{5, 6, 4});
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(result != nullptr);
    CHECK(result->val == 7);
    CHECK(result->next != nullptr);
    CHECK(result->next->val == 0);
    CHECK(result->next->next != nullptr);
    CHECK(result->next->next->val == 8);
    CHECK(result->next->next->next == nullptr);
    CHECK(ListNode::equal({7, 0, 8}, result));
    for (auto &i: vec1) {
        delete i;
    }
    for (auto &i: vec2) {
        delete i;
    }
}

TEST_CASE("basic tests 2 [test 2]", "[test 2]") {
    vector<ListNode *> vec1 = ListNode::numToList(vector<int>{0});
    vector<ListNode *> vec2 = ListNode::numToList(vector<int>{0});
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(result != nullptr);
    CHECK(result->val == 0);
    CHECK(ListNode::equal({0}, result));
    for (auto &i: vec1) {
        delete i;
    }
    for (auto &i: vec2) {
        delete i;
    }
}

TEST_CASE("basic tests 3 [test 2]", "[test 2]") {
    vector<ListNode *> vec1 = ListNode::numToList(vector<int>{9, 9, 9, 9, 9, 9, 9});
    vector<ListNode *> vec2 = ListNode::numToList(vector<int>{9, 9, 9, 9});
    const ListNode *const result = leetcode_2::addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({8, 9, 9, 9, 0, 0, 0, 1}, result));
    for (auto &i: vec1) {
        delete i;
    }
    for (auto &i: vec2) {
        delete i;
    }
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_HPP
