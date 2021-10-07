/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021 nanoseeds

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
/*
 *@题目描述
 * */
//@Tag DONE
#ifdef CS203_DSAA_MACRO_TREENODE

#else
#include <cstdint>
#include <cstddef>
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("sse,sse2,mmx")
#endif //CS203_DSAA_MACRO_TREENODE

#include <tuple>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_04_D{
#endif
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using std::unordered_set;

static constexpr const char end{'\n'}, space{' '};

namespace AVL_TREE {
template<typename T>
struct TreeNode {
    explicit TreeNode(T value) : val(value) {}

    T val;
    size_t height{};
    TreeNode<T> *left{nullptr}, *right{nullptr};
};

template<typename T>
class AVLTree {
public:
    AVLTree() = default;            //构造函数
    ~AVLTree() {
        destory(root);
    };            //析构函数
    inline void insert(T key) {
        insert(root, key);
    };
    TreeNode<T> *root{nullptr};    //AVL树的根节点
    size_t height(TreeNode<T> *const pnode) {
        if (pnode != nullptr) {
            return pnode->height;
        }
        return static_cast<size_t>(0);
    }

    TreeNode<T> *getPreNode(T value);

    TreeNode<T> *getNextNode(T value);

private:
    void destory(TreeNode<T> *const pnode) {
        if (pnode != nullptr) {
            destory(pnode->left);
            destory(pnode->right);
            delete pnode;
        }
    }

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
    proot->height = std::max(height(proot->left), height(proot->right)) + 1;     //更新节点的高度值
    pright->height = std::max(proot->height, height(pright->right)) + 1; //更新节点的高度值
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
    proot->height = std::max(height(proot->left), height(proot->right)) + 1;     //更新节点的高度值
    pleft->height = std::max(height(pleft->left), proot->height) + 1; //更新节点的高度值
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
    pnode->height = std::max(height(pnode->left), height(pnode->right)) + 1;
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
TreeNode<T> *AVLTree<T>::getPreNode(T value) {
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
TreeNode<T> *AVLTree<T>::getNextNode(T value) {
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
using num_t = int32_t;
using input_type = vector<num_t>;
using output_type = vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int32_t main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t alpha;
    std::cin >> alpha;
    vector<num_t> weights(alpha);
    for (auto &weight: weights) {
        std::cin >> weight;
    }
    return weights;
}

output_type cal(const input_type &data) {
    vector<num_t> will_return{};
    will_return.reserve(data.size() - 1);
    AVL_TREE::AVLTree<num_t> tree;
    std::unordered_set<num_t> uset;
    tree.insert(*data.crbegin());
    uset.insert(*data.crbegin());
    for (auto iter = data.crbegin() + 1; iter != data.crend(); ++iter) {
        if (uset.find(*iter) != uset.end()) {
            will_return.emplace_back(0);
            continue;
        }
        tree.insert(*iter);
        uset.insert(*iter);
        const AVL_TREE::TreeNode<num_t> *const prev = tree.getPreNode(*iter),
                *const next = tree.getNextNode(*iter);
        if (next != nullptr && prev != nullptr) {
            will_return.emplace_back(
                    std::min(std::abs(next->val - *iter),
                             std::abs(prev->val - *iter))
            );
        } else if (prev != nullptr) {
            will_return.emplace_back(std::abs(prev->val - *iter));
        } else {
            assert(next != nullptr);
            will_return.emplace_back(std::abs(next->val - *iter));
        }
    }
    return will_return;
}

void output(const output_type &data) {
    for (auto iter = data.crbegin(); iter != data.crend() - 1; ++iter) {
        std::cout << (*iter) << space;
    }
    std::cout << *(data.crend() - 1);
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
