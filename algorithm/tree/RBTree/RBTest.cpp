/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-06 22:42:27 
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020  nanoseeds

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
#include <vector>
#include "catch_main.hpp"
#include "RBTree.hpp"

using std::cout;
using std::endl;

TEST_CASE("bulit node", "[RBNode]") {
    auto temp = RBTNode<int>(1, RBTColor::Red, nullptr, nullptr, nullptr);
}

TEST_CASE("bulit node pointer", "[RBNode]") {
    auto *temp = new RBTNode<int>(1, RBTColor::Black, nullptr, nullptr, nullptr);
    delete temp;
}

TEST_CASE("bulit tree", "[RBTree]") {
    RBTree<int> temp;
    REQUIRE(temp.root == nullptr);
}

TEST_CASE("bulit tree pointer", "[RBTree]") {
    auto *temp = new RBTree<int>();
    delete temp;
}

//TODO unfinish, still need fix.
SCENARIO("insert tree value", "[RBTree]") {
    RBTree<int> temp;
    WHEN("initial zero point") {
        REQUIRE(temp.root == nullptr);
    }

    WHEN("one node") {
        temp.insert(1);
        THEN("the values") {
            CHECK(temp.root->get_key() == 1);
        }THEN("the nodes connections") {
            CHECK(temp.root->get_right() == nullptr);
            CHECK(temp.root->get_left() == nullptr);
            CHECK(temp.root->get_parent() == nullptr);
        }THEN("test colors") {
            CHECK(temp.root->get_color() == RBTColor::Black);
        }
    }

    WHEN("two node") {
        temp.insert({1, 2});
        THEN("the head is still 1") {
            CHECK(temp.root->get_key() == 1);
            CHECK(temp.root->get_right()->get_key() == 2);
        }THEN("the needs connections") {
            CHECK(temp.root->get_right()->get_key() == 2);
            CHECK(temp.root->get_left() == nullptr);
            CHECK(temp.root->get_parent() == nullptr);

            CHECK((temp.root->get_right())->get_left() == nullptr);
            CHECK((temp.root->get_right())->get_right() == nullptr);
            CHECK(temp.root->get_right()->get_parent()->get_key() == 1);
        }THEN("test colors") {
            CHECK(temp.root->get_color() == RBTColor::Black);
            CHECK(temp.root->get_right()->get_color() == RBTColor::Red);
        }
    }

    WHEN("three node") {
        temp.insert({1, 2, 3});
        THEN("the head is still 1") {
            CHECK(temp.root->get_key() == 2);
            CHECK(temp.root->get_left()->get_key() == 1);
            CHECK(temp.root->get_right()->get_key() == 3);
        }THEN("the needs connections") {
            CHECK(temp.root->get_left()->get_key() == 1);
            CHECK(temp.root->get_right()->get_key() == 3);
            CHECK(temp.root->get_parent() == nullptr);

            CHECK(temp.root->get_right()->get_left() == nullptr);
            CHECK(temp.root->get_right()->get_right() == nullptr);
            CHECK(temp.root->get_right()->get_parent()->get_key() == 2);

            CHECK(temp.root->get_left()->get_left() == nullptr);
            CHECK(temp.root->get_left()->get_right() == nullptr);
            CHECK(temp.root->get_left()->get_parent()->get_key() == 2);
        }THEN("test colors") {
            CHECK(temp.root->get_color() == RBTColor::Black);
            CHECK(temp.root->get_left()->get_color() == RBTColor::Red);
            CHECK(temp.root->get_right()->get_color() == RBTColor::Red);
        }
    }
}
