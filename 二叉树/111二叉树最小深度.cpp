#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 递归
int getDepth(TreeNode* root)
{
    if(root == nullptr) return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    
    // 这里和最大深度不同
    if(root->left == nullptr && root->right != nullptr)
    {
        return right + 1;
    }
    if(root->right == nullptr && root->left != nullptr)
    {
        return left + 1;
    }
    return 1 + min(left,right);
}

// 层序遍历
int cengxu(TreeNode* root)
{
    if(root == nullptr) return 0;
    queue<TreeNode*> que;
    int result;
    que.push(root);
    while(!que.empty())
    {
        int size = que.size();
        result++;
        for(int i = 0;i < size;i++)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            if(node->left == nullptr && node->right == nullptr)
            {
                return result;
            }
        }

    }
}