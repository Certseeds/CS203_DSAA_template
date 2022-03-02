// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

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