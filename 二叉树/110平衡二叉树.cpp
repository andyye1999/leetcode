#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int gaodu(TreeNode* root)
{
    if(root == nullptr) return 0;
    int left = gaodu(root->left);
    if(left == -1) return -1; // 跟最大深度比一样的地方
    int right = gaodu(root->right);
    if(right == -1) return -1;

    return labs(left - right) > 1 ? -1 : 1 + max(left,right);
}

bool pingheng(TreeNode* root)
{
    return gaodu(root) == -1 ? false : true;
}