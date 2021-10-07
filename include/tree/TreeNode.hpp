/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:34:16
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-01-03 21:01:19
 */
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP

#include <TreeNodeTemp.hpp>
#include <vector>

namespace TREE_NODE {
using TREE_NODE_TEMP::TreeNodeTemp;
using std::vector;
template<typename T>
struct TreeNode: public TreeNodeTemp<T,TreeNode>{
private:
    using base = TreeNodeTemp<T,TreeNode>;
public:
    explicit TreeNode(T x): base(x){}
    static constexpr const T No{static_cast<T>(-100000)};
};

template<typename T>
static void organize(vector<TreeNode<T> *> Tree) {
    size_t tree_size{Tree.size()};
    for (size_t i{0}; i < tree_size; i++) {
        if (Tree[i] != nullptr) {
            Tree[i]->left = (2 * i + 1 < tree_size) ? Tree[2 * i + 1] : nullptr;
            Tree[i]->right = (2 * i + 2 < tree_size) ? Tree[2 * i + 2] : nullptr;
        }
    }
}
template<typename T>
static vector<TreeNode<T> *> numToTree(const vector<T> &nums) {
    const auto nums_size = nums.size();
    vector<TreeNode<T> *> will_return(nums_size, nullptr);
    for (size_t i{0}; i < nums_size; i++) {
        will_return[i] = (nums[i] != TreeNode<T>::No) ? new TreeNode<T>(nums[i]) : nullptr;
    }
    organize(will_return);
    return will_return;
}
};

#endif  //CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP