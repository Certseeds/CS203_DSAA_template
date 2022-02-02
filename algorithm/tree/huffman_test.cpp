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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP

#include <catch_main.hpp>
#include "huffman.cpp"

namespace tree::huffman {

TEST_CASE("test_case 1 [test_tree_huffman]", "[test_tree_huffman]") {
    const huffman hn{"1145141919810"};
    const string str{"1919810"};
    CHECK(str == hn.decal(hn.cal(str)));
}
TEST_CASE("test_case 2 [test_tree_huffman]", "[test_tree_huffman]") {
    const huffman hn{"An awesome Algorithm template for Solve Online-Judge !"};
    const string str{"An awesome for Solve Online-Judge !"};
    CHECK(str == hn.decal(hn.cal(str)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP
