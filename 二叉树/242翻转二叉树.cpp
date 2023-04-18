#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* fanzhuan(TreeNode* root)
{
    if(root == nullptr) return root;
    swap(root->left,root->right);
    fanzhuan(root->left);
    fanzhuan(root->right);
    return root;
}