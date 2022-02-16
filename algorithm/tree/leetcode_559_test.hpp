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
//@Tag tree
//@Tag 树
//@Tag DFS
//@Tag 深度优先遍历
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode_multi.hpp>
#include <stack>

namespace leetcode_559 {

using Node = TREE_NODE::TreeNodeMulti;
using std::stack;

struct leetcode_559 {
    static int maxDepth(Node *root);
};

TEST_CASE("test_case 1 [test_559]", "[test_559]") {
    CHECK(true); // too simple
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_559_HPP
