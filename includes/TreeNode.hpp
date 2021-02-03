/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:34:16
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-01-03 21:01:19
 */
#ifndef CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP
#define CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP

#include <vector>

using std::vector;
constexpr int No = -100000;

class TreeNode {
public:
    int32_t val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x = 0) : TreeNode(x, nullptr, nullptr) {};

    TreeNode(int x, TreeNode *le, TreeNode *rig) : val(x), left(le), right(rig) {};

    TreeNode(const TreeNode &obj) {
        this->val = obj.val;
        this->left = obj.left;
        this->right = obj.right;
    }

    TreeNode &operator=(const TreeNode &node) = delete;

    TreeNode(TreeNode &&node) = delete;

    TreeNode &operator=(TreeNode &&node) = delete;

    ~TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    static vector<TreeNode *> numToTree(const vector<int> &nums) {
        vector<TreeNode *> will_return(nums.size(), nullptr);
        for (int i = 0; i < static_cast<int32_t>(nums.size()); i++) {
            will_return[i] = (nums[i] != No) ? new TreeNode(nums[i]) : nullptr;
        }
        TreeNode::organize(will_return);
        return will_return;
    }

    static void organize(vector<TreeNode *> Tree) {
        int32_t tree_size = Tree.size();
        for (int i = 0; i < tree_size; i++) {
            if (Tree[i] != nullptr) {
                Tree[i]->left = (2 * i + 1 < tree_size) ? Tree[2 * i + 1] : nullptr;
                Tree[i]->right = (2 * i + 2 < tree_size) ? Tree[2 * i + 2] : nullptr;
            }
        }
    }
};

#endif  //CS203_DSAA_TEMPLATE_INCLUDES_TREENODE_HPP