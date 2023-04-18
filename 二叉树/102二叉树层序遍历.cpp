#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

vector<vector<int>> cengxu(TreeNode* cur)
{
    queue<TreeNode*> que; // 注意容器是TreeNode* 
    vector<vector<int>> result;
    if(cur != nullptr) que.push(cur);
    while(!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for(int i = 0;i < size;i++)
        {
            TreeNode* node = que.front();
            vec.push_back(node->val);
            que.pop();
            if(node->left) que.push(node->left); // 忘记加if了
            if(node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}