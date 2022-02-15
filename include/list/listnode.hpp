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
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP

#include <cstdint>
#include <cstddef>
#include <utility>
#include <vector>


namespace LISTNODE {
using std::vector;
static size_t alloc_delete_count{0};

struct ListNode {
    int32_t val;
    ListNode *next;

    ListNode(int32_t v, ListNode *n) : val(v), next(n) {
        alloc_delete_count++;
    }

    explicit ListNode(int32_t x) : ListNode(x, nullptr) {};

    ListNode(const ListNode &obj) : ListNode(obj.val, obj.next) {};

    ~ListNode() {
        alloc_delete_count--;
    }


    static bool equal(const vector<int32_t> &nums, const ListNode *node);

    static bool equal(const std::initializer_list<int32_t> &nums, const ListNode *node);
};

class ListNodeLink final {
private:
    static constexpr const int32_t No_list = -100000;
public:
    vector<ListNode *> list{};

    ListNodeLink(std::initializer_list<int32_t> list_) : list(numToList(list_)) {}

    explicit ListNodeLink(vector<ListNode *> list_) : list(std::move(list_)) {}

    explicit ListNodeLink(ListNode *node) {
        while (node != nullptr) {
            list.push_back(node);
            node = node->next;
        }
    }

    virtual ~ListNodeLink() {
        for (auto &i: list) {
            delete i;
        }
    }

    ListNode *operator[](size_t i) const {
        if (i >= list.size()) {
            return nullptr;
        }
        return list.at(i);
    }

    ListNode *operator[](size_t i) {
        return const_cast<ListNode *>(
                static_cast<const ListNodeLink &>(*this)[i]
        );
    }

private:
    static vector<ListNode *> numToList(vector<int32_t> nums) {
        const auto nums_size{nums.size()};
        vector<ListNode *> will_return(nums_size, nullptr);
        for (size_t i{0}; i < nums_size; i++) {
            will_return[i] = (nums[i] != No_list) ? new ListNode(nums[i]) : nullptr;
        }
        for (size_t i{0}; i + 1 < nums_size; i++) {
            will_return[i]->next = will_return[i + 1];
        }
        return will_return;
    }

    static vector<ListNode *> numToList(std::initializer_list<int32_t> nums) {
        return ListNodeLink::numToList(vector<int32_t>{nums});
    }
};


bool ListNode::equal(const vector<int32_t> &nums, const ListNode *const node) {
    if (node == nullptr) {
        return nums.empty();
    }
    ListNode const *n = node;
    for (size_t i{0}; i < nums.size(); ++i) {
        if (nums[i] != n->val) {
            return false;
        }
        if (n->next == nullptr && i == nums.size() - 1) {
            return true;
        }
        n = n->next;
    }
    return false;
}

bool ListNode::equal(const std::initializer_list<int32_t> &nums, const ListNode *const node) {
    return ListNode::equal(vector<int32_t>(nums), node);
}
}
#endif //CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP