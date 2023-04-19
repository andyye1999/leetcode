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

// 层序遍历
int cengxu(TreeNode* root)
{
    if(root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        int size = que.size();
        depth++;
        for(int i = 0;i < size;i++)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return depth;
}

// 递归
int digui(TreeNode* root)
{
    if(root == nullptr) return 0;
    int left = digui(root->left);
    int right = digui(root->right);
    return 1 + max(left,right); // 注意是1+
}

