#include <iostream>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


// 忽略头节点
bool duichen(TreeNode* left,TreeNode* right)
{
    // 首先排除空节点的情况
    if (left == NULL && right != NULL) return false;
    else if (left != NULL && right == NULL) return false;
    else if (left == NULL && right == NULL) return true;
    // 排除了空节点，再排除数值不相同的情况
    else if (left->val != right->val) return false;
    else return duichen(left->left,right->right) && duichen(left->right,right->left);
}

bool solution(TreeNode* root)
{
    if(root == nullptr) return true;
    return duichen(root->left,root->right);
}
