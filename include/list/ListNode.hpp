#ifndef CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP
#ifdef CS203_DSAA_MACRO_LISTNODE

#include <utility>
#include <vector>
/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2020-02-02 21:01:26
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 09:30:22
 */
namespace LISTNODE {
using std::vector;
static constexpr const int32_t No_list = -100000;
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
        this->val = 0;
        this->next = nullptr;
        alloc_delete_count--;
    }

    static vector<ListNode *> numToList(vector<int32_t> nums);

    static vector<ListNode *> numToList(std::initializer_list<int32_t> nums);

    static bool equal(const vector<int32_t> &nums, const ListNode *node);

    static bool equal(const std::initializer_list<int32_t> &nums, const ListNode *node);
};

class ListNodeLink {
public:
    vector<ListNode *> list{};

    ListNodeLink(std::initializer_list<int32_t> list_) : list(ListNode::numToList(list_)) {
    }

    ListNodeLink(vector<ListNode *> list_) : list(std::move(list_)) {}

    virtual ~ListNodeLink() {
        for (auto &i: list) {
            delete i;
        }
    }

    ListNode *operator[](size_t i) {
        if (i >= list.size()) {
            return nullptr;
        }
        return list[i];
    }
};

vector<ListNode *> ListNode::numToList(vector<int32_t> nums) {
    vector<ListNode *> will_return(nums.size(), nullptr);
    for (size_t i = 0; i < nums.size(); i++) {
        will_return[i] = (nums[i] != No_list) ? new ListNode(nums[i]) : nullptr;
    }
    for (size_t i = 0; i < nums.size() - 1; i++) {
        will_return[i]->next = will_return[i + 1];
    }
    return will_return;
}

vector<ListNode *> ListNode::numToList(std::initializer_list<int32_t> nums) {
    return ListNode::numToList(vector<int32_t>{nums});
}

bool ListNode::equal(const vector<int32_t> &nums, const ListNode *const node) {
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
#endif
#endif //CS203_DSAA_TEMPLATE_INCLUDES_LISTNODE_HPP