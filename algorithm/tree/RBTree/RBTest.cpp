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
#include <random>
#include <vector>
#include "catch_main.hpp"
#include "RBTree.hpp"

using std::cout;
using std::endl;

TEST_CASE("bulit node", "[RBNode]") {
    auto temp = RBTNode<int>(1, RBTColor::Red);
}

TEST_CASE("bulit node pointer", "[RBNode]") {
    const auto temp = std::make_unique<RBTNode<int32_t>>(1, RBTColor::Black);
}

TEST_CASE("bulit tree", "[RBTree]") {
    const auto temp = RBTree<int32_t>();
    REQUIRE(temp.size == 0);
}

TEST_CASE("auto pointer tree", "[RBTree]") {
    const auto temp = std::make_unique<RBTree<int32_t>>();
    REQUIRE(temp->size == 0);
}

TEST_CASE("bulit tree pointer", "[RBTree]") {
    const auto *const temp = new RBTree<int>();
    delete temp;
}

SCENARIO("insert tree value", "[RBTree]") {
    RBTree<int32_t> temp;
    WHEN("initial zero point") {
        REQUIRE(temp.size == 0);
    }THEN(" self check") {
        temp.check();
    }

    WHEN("one node") {
        temp.insert(1);
        THEN("the values") {
            CHECK(*temp.root == 1);
        }THEN(" self check") {
            temp.check();
        }
    }

    WHEN("two node") {
        temp.insert({1, 2});
        THEN("the head is still 1") {
            CHECK(*temp.root == 1);
            CHECK(*temp.root->right == 2);
        }THEN("the needs connections") {
            CHECK(*temp.root->right == 2);

            CHECK(*temp.root->right->parent == 1);
        }THEN("test colors") {
            CHECK(temp.root->isBlack());
            CHECK(temp.root->right->isRed());
        }THEN(" self check") {
            temp.check();
        }
    }

    WHEN("three node") {
        temp.insert({1, 2, 3});
        THEN("the head is 2") {
            CHECK(*temp.root == std::make_tuple(2, 1, 3));
        }THEN("the needs connections") {
            CHECK(*temp.root->right->parent == 2);
            CHECK(*temp.root->left->parent == 2);
        }THEN("test colors") {
            temp.pre_order();
        }THEN("test size") {
            REQUIRE(temp.size == 3);
        }THEN(" self check") {
            temp.check();
        }
    }
}

TEST_CASE("insert test for 11 node", "[RBTree]") {
    auto initilist = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    auto vec_list = vector<int32_t>(initilist);
    const auto temp = std::make_unique<RBTree<int32_t>>(initilist);
    CHECK(*temp->root == vec_list[3]);
    CHECK(*temp->root->left == vec_list[1]);
    CHECK(*temp->root->right == vec_list[5]);

    CHECK(*temp->root->left->left == vec_list[0]);
    CHECK(*temp->root->left->right == vec_list[2]);
    CHECK(*temp->root->right->left == vec_list[4]);
    CHECK(*temp->root->right->right == vec_list[7]);

    CHECK(*temp->root->right->right->left == vec_list[6]);
    CHECK(*temp->root->right->right->right == vec_list[8]);
    temp->check();
}

TEST_CASE("insert check function", "[RBTree][.]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int32_t> vec_list(initilist);
    while (std::next_permutation(vec_list.begin(), vec_list.end())) {
        const auto temp = std::make_unique<RBTree<int32_t>>(initilist);
        temp->pre_order();
        REQUIRE(temp->size == initilist.size());
        THEN(" self check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 3 function", "[RBTree]") { //passed
    auto initilist = {1, 2, 3};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        while (std::next_permutation(in_list.begin(), in_list.end())) {
            std::cout << "begin ";
            std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            std::cout << "delete ";
            std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
            temp->pre_order();
            REQUIRE(temp->size == out_list.size());
            THEN(" self check") {
                temp->check();
            }
            for (const auto &j: in_list) {
                WHEN("remove element") {
                    temp->remove(j);
                }THEN("output") {
                    temp->pre_order();
                }THEN("check") {
                    temp->check();
                }
            }
        }
    }
}

TEST_CASE("insert delete size 3 function- single", "[RBTree]") { //passed
    auto initilist = {2, 1, 3};
    vector<int32_t> vec_list(initilist);
    std::for_each(vec_list.begin(), vec_list.end(), [](auto i) { std::cout << i << ", "; });
    std::cout << endl;
    const auto temp = std::make_unique<RBTree<int32_t>>(initilist);
    temp->pre_order();
    REQUIRE(temp->size == initilist.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: vec_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 4 function", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        while (std::next_permutation(in_list.begin(), in_list.end())) {
            std::cout << "begin ";
            std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            std::cout << "delete ";
            std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
            temp->pre_order();
            REQUIRE(temp->size == out_list.size());
            THEN(" self check") {
                temp->check();
            }
            for (const auto &j: in_list) {
                WHEN("remove element") {
                    temp->remove(j);
                }THEN("output") {
                    temp->pre_order();
                }THEN("check") {
                    temp->check();
                }
            }
        }
    }
}

TEST_CASE("insert delete size 4 function single", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4};
    vector<int32_t> out_list({1, 3, 2, 4});
    vector<int32_t> in_list(initilist);
    //while (std::next_permutation(in_list.begin(), in_list.end())) {
    std::cout << "begin ";
    std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
    std::cout << std::endl;
    //std::cout << "delete ";
    // std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
    //std::cout << std::endl;
    const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
    temp->pre_order();
    REQUIRE(temp->size == out_list.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: in_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
    //}
}

TEST_CASE("insert delete size 5 function", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        while (std::next_permutation(in_list.begin(), in_list.end())) {
            std::cout << "begin ";
            std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            //std::cout << "delete ";
            // std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
            //std::cout << std::endl;
            const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
            temp->pre_order();
            REQUIRE(temp->size == out_list.size());
            THEN(" self check") {
                temp->check();
            }
            for (const auto &j: in_list) {
                WHEN("remove element") {
                    temp->remove(j);
                }THEN("output") {
                    temp->pre_order();
                }THEN("check") {
                    temp->check();
                }
            }
        }
    }
}

TEST_CASE("insert delete size 6 function", "[RBTree][.]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        while (std::next_permutation(in_list.begin(), in_list.end())) {
            std::cout << "begin ";
            std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            std::cout << "delete ";
            std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
            std::cout << std::endl;
            const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
            temp->pre_order();
            REQUIRE(temp->size == out_list.size());
            THEN(" self check") {
                temp->check();
            }
            for (const auto &j: in_list) {
                WHEN("remove element") {
                    temp->remove(j);
                }THEN("output") {
                    temp->pre_order();
                }THEN("check") {
                    temp->check();
                }
            }
        }
    }
}

TEST_CASE("insert delete size 6 function single 1", "[RBTree]") { //passed
    vector<int32_t> out_list({1, 2, 3, 4, 6, 5});
    vector<int32_t> in_list({2, 4, 5, 1, 3, 6});
    const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
    temp->pre_order();
    REQUIRE(temp->size == out_list.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: in_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 6 function single 2", "[RBTree]") { //passed
    vector<int32_t> out_list({1, 2, 3, 5, 4, 6});
    vector<int32_t> in_list({1, 2, 3, 4, 6, 5});
    const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
    temp->pre_order();
    REQUIRE(temp->size == out_list.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: in_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 6 function single 3", "[RBTree]") { //passed
    vector<int32_t> out_list({1, 2, 4, 5, 6, 3});
    vector<int32_t> in_list({1, 5, 2, 3, 4, 6});
    const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
    temp->pre_order();
    REQUIRE(temp->size == out_list.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: in_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 6 function single 4", "[RBTree]") { //passed
    vector<int32_t> out_list({1, 5, 6, 2, 3, 4});
    vector<int32_t> in_list({1, 5, 2, 3, 4, 6});
    const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
    temp->pre_order();
    REQUIRE(temp->size == out_list.size());
    THEN(" self check") {
        temp->check();
    }
    for (const auto &j: in_list) {
        WHEN("remove element") {
            temp->remove(j);
        }THEN("output") {
            temp->pre_order();
        }THEN("check") {
            temp->check();
        }
    }
}

TEST_CASE("insert delete size 7 function order 1", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        //while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "begin ";
        std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            temp->remove(j);
            temp->pre_order();
            temp->check();
        }
        //}
    }
}

TEST_CASE("insert delete size 7 function order 2", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    //while (std::next_permutation(out_list.begin(), out_list.end())) {
    while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "delete ";
        std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            temp->remove(j);
            temp->pre_order();
            temp->check();
        }
    }
    //}
}

TEST_CASE("insert delete size 8 function order 1", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        //while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "begin ";
        std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
        //}
    }
}

TEST_CASE("insert delete size 8 function order 2", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    //while (std::next_permutation(out_list.begin(), out_list.end())) {
    while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "delete ";
        std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
    }
    //}
}

TEST_CASE("insert delete size 9 function order 1", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        //while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "begin ";
        std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
        //}
    }
}

TEST_CASE("insert delete size 9 function order 2", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    //while (std::next_permutation(out_list.begin(), out_list.end())) {
    while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "delete ";
        std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
    }
    //}
}

TEST_CASE("insert delete size 10 function order 1", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    while (std::next_permutation(out_list.begin(), out_list.end())) {
        //while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "begin ";
        std::for_each(out_list.begin(), out_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
        //}
    }
}

TEST_CASE("insert delete size 10 function order 2", "[RBTree]") { //passed
    auto initilist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int32_t> out_list(initilist);
    vector<int32_t> in_list(initilist);
    //while (std::next_permutation(out_list.begin(), out_list.end())) {
    while (std::next_permutation(in_list.begin(), in_list.end())) {
        std::cout << "delete ";
        std::for_each(in_list.begin(), in_list.end(), [](auto i) { std::cout << i << ", "; });
        std::cout << std::endl;
        const auto temp = std::make_unique<RBTree<int32_t>>(out_list.cbegin(), out_list.cend());
        temp->pre_order();
        REQUIRE(temp->size == out_list.size());
        THEN(" self check") {
            temp->check();
        }
        for (const auto &j: in_list) {
            WHEN("remove element") {
                temp->remove(j);
            }THEN("output") {
                temp->pre_order();
            }THEN("check") {
                temp->check();
            }
        }
    }
    //}
}
