#include <iostream>
#include <algorithm>
#include "avl_node.hpp"

namespace AVL_TREE {
using std::max, std::cout, std::endl;

template<typename T>
class AVLTree {
private:
    TreeNode<T> *root{nullptr};    //AVL树的根节点
public:
    AVLTree() = default;            //构造函数
    ~AVLTree() { delete this->root; };            //析构函数
    inline void insert(T key) { insert(this->root, key); };

    size_t height(TreeNode<T> *const pnode) const {
        if (pnode != nullptr) {
            return pnode->height;
        }
        return static_cast<size_t>(0);
    }

    TreeNode<T> *getPreNode(T value) const;

    TreeNode<T> *getNextNode(T value) const;

private:
    TreeNode<T> *insert(TreeNode<T> *&pnode, T key);

    TreeNode<T> *leftRotation(TreeNode<T> *proot);        //单旋:左旋操作
    TreeNode<T> *rightRotation(TreeNode<T> *proot);        //单旋:右旋操作
    inline TreeNode<T> *leftRightRotation(TreeNode<T> *proot);    //双旋:先左旋后右旋操作
    inline TreeNode<T> *rightLeftRotation(TreeNode<T> *proot);    //双旋:先右旋后左旋操作

};
/*左旋转操作*/
/*pnode为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
TreeNode<T> *AVLTree<T>::leftRotation(TreeNode<T> *proot) {
    TreeNode<T> *const pright = proot->right;
    proot->right = pright->left;
    pright->left = proot;
    proot->height = max(height(proot->left), height(proot->right)) + 1;     //更新节点的高度值
    pright->height = max(proot->height, height(pright->right)) + 1; //更新节点的高度值
    return pright;
};

/*右旋转操作*/
/*pnode为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
TreeNode<T> *AVLTree<T>::rightRotation(TreeNode<T> *proot) {
    TreeNode<T> *const pleft = proot->left;
    proot->left = pleft->right;
    pleft->right = proot;
    proot->height = max(height(proot->left), height(proot->right)) + 1;     //更新节点的高度值
    pleft->height = max(height(pleft->left), proot->height) + 1; //更新节点的高度值
    return pleft;
};

/*先左后右做旋转*/
/*参数proot为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
TreeNode<T> *AVLTree<T>::leftRightRotation(TreeNode<T> *proot) {
    proot->left = leftRotation(proot->left);
    return rightRotation(proot);
};
/*先右旋再左旋*/
/*参数proot为最小失衡子树的根节点*/
/*返回旋转后的根节点*/
template<typename T>
TreeNode<T> *AVLTree<T>::rightLeftRotation(TreeNode<T> *proot) {
    proot->right = rightRotation(proot->right);
    return leftRotation(proot);
};

/*插入操作*/
/*递归地进行插入*/
/*返回插入后的根节点*/
template<typename T>
TreeNode<T> *AVLTree<T>::insert(TreeNode<T> *&pnode, T key) {
    if (pnode == nullptr) {   //寻找到插入的位置
        pnode = new TreeNode<T>(key);
    } else if (key > pnode->val) {    //插入值比当前结点值大，插入到当前结点的右子树上
        pnode->right = insert(pnode->right, key);
        if (height(pnode->right) - height(pnode->left) == 2) { //插入后出现失衡
            if (key > pnode->right->val) {//情况一：插入右子树的右节点，进行左旋
                pnode = leftRotation(pnode);
            } else if (key < pnode->right->val) {  //情况三：插入右子树的左节点,进行先右再左旋转
                pnode = rightLeftRotation(pnode);
            }
        }
    } else if (key < pnode->val) {//插入值比当前节点值小，插入到当前结点的左子树上
        pnode->left = insert(pnode->left, key);
        if (height(pnode->left) - height(pnode->right) == 2) { //如果插入导致失衡
            if (key < pnode->left->val) {      //情况二：插入到左子树的左孩子节点上，进行右旋
                pnode = rightRotation(pnode);
            } else if (key > pnode->left->val) {
                pnode = leftRightRotation(pnode); //情况四：插入到左子树的右孩子节点上，进行先左后右旋转
            }
        }
    }
    pnode->height = max(height(pnode->left), height(pnode->right)) + 1;
    return pnode;
}


template<typename T>
TreeNode<T> *getRightNode(TreeNode<T> *root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

//主函数
template<typename T>
TreeNode<T> *AVLTree<T>::getPreNode(T value) const {
    if (this->root == nullptr) {
        return nullptr;
    }
    TreeNode<T> *parent{nullptr}, *firstRParent{nullptr};
    const auto getPNode = [&parent, &firstRParent](TreeNode<T> *proot, T value) {
        while (proot != nullptr) {
            if (proot->val == value) {
                return proot;
            }
            parent = proot;
            if (proot->val > value) {
                proot = proot->left;
            } else {
                firstRParent = proot;//出现右拐点
                proot = proot->right;
            }
        }
        return static_cast<TreeNode<T> *>(nullptr);
    };
    TreeNode<T> *const node = getPNode(this->root, value);
    if (node == nullptr) {
        return node;
    } else if (node->left != nullptr) { //有左子树
        return getRightNode(node->left);
    } else if (nullptr == parent || nullptr == firstRParent) {
        return nullptr; //没有前驱节点的情况
    } else if (node == parent->right) { //没有左子树 是其父节点的右边节点
        return parent;
    } else {//没有左子树 是其父节点的左边节点
        return firstRParent;
    }
}

template<typename T>
TreeNode<T> *getLeftNode(TreeNode<T> *root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

template<typename T>
TreeNode<T> *AVLTree<T>::getNextNode(T value) const {
    if (this->root == nullptr) {
        return nullptr;
    }
    TreeNode<T> *parent{nullptr}, *firstlParent{nullptr};
    const auto getNode = [&parent, &firstlParent](TreeNode<T> *proot, T value) {
        while (proot != nullptr) {
            if (proot->val == value) {
                return proot;
            }
            parent = proot;//设置父亲节点
            if (proot->val < value) {
                proot = proot->right;
            } else {
                firstlParent = proot;//发生了左拐
                proot = proot->left;
            }
        }
        return static_cast<TreeNode<T> *>(nullptr);
    };
    TreeNode<T> *const node = getNode(this->root, value);
    if (node == nullptr) {
        return node;
    } else if (node->right != nullptr) {//有右子树
        return getLeftNode(node->right);
    } else if (nullptr == parent || nullptr == firstlParent) { return nullptr; } //没有后继节点的情况
    else if (node == parent->left) {//没有右子树 是其父节点的左边节点
        return parent;
    } else {//没有右子树 是其父节点的右边节点
        return firstlParent;
    }

}
}
namespace AVL_TREE {
int main() {
    AVLTree<int32_t> temp{};
    temp.insert(100);
    for (auto &&ele: {200, 95, 96, 101, 104, 323, 456, 1, 2, 3, 4, 5}) {
        temp.insert(ele);
        const auto *const pointer = temp.getPreNode(ele);
        if (pointer != nullptr) {
            cout << pointer->val << " ";
        } else {
            cout << " \\ ";
        }
        const auto *const pointer2 = temp.getNextNode(ele);
        if (pointer2 != nullptr) {
            cout << pointer2->val << " ";
        } else {
            cout << " \\ ";
        }
        cout << '\n';
    }
    return 0;
}
}

int main() {
    for(auto&& v:{1,2,3,4,5}){
        std::cout << v << std::endl;
    }
    exit(163);
}
