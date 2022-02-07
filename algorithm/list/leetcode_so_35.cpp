/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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
#include "leetcode_so_35_test.hpp"

namespace leetcode_so_35 {

Node *leetcode_so_35::copyRandomList(Node *head) {
    std::unordered_map<std::intptr_t, size_t> umap;
    Node *head2 = head;
    for (size_t i{0}; head2 != nullptr; head2 = head2->next, ++i) {
        umap[reinterpret_cast<std::intptr_t>(head2)] = i;
    }
    const auto length = umap.size();
    vector<size_t> random_map(length);
    Node *head3 = head;
    for (size_t i{0}; head3 != nullptr; head3 = head3->next, ++i) {
        if (head3->random == nullptr) {
            random_map[i] = std::numeric_limits<size_t>::max();
        } else {
            random_map[i] = umap[reinterpret_cast<std::intptr_t>(head3->random)];
        }
    }
    std::vector<Node *> nodes(length);
    Node *head4 = head;
    for (size_t i{0}; head4 != nullptr; head4 = head4->next, ++i) {
        nodes[i] = new Node(head4->val);
    }
    for (size_t i{0}; i + 1 < length; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    for (size_t i{0}; i < length; ++i) {
        if (random_map[i] != std::numeric_limits<size_t>::max()) {
            nodes[i]->random = nodes[random_map[i]];
        }
    }
    return nodes[0];
}
}