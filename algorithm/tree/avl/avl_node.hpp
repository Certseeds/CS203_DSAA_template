#include <TreeNodeTemp.hpp>
namespace AVL_TREE {
using TREE_NODE_TEMP::TreeNodeTemp;
template<typename T>
struct TreeNode: public TreeNodeTemp<T,TreeNode>{
private:
    using base = TreeNodeTemp<T,TreeNode>;
public:
    explicit TreeNode(T x): base(x){}
    size_t height{};
    ~TreeNode() override {
        this->val = 0;
        delete this->left;
        delete this->right;
        this->left = nullptr;
        this->right = nullptr;
    }
};
}
