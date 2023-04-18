#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 前序遍历
void qianxu(TreeNode* cur,vector<int> &vec)
{
    if(cur == nullptr) return;
    vec.push_back(cur->val);
    qianxu(cur->left,vec);
    qianxu(cur->right,vec);
}

// 中序遍历
void zhongxu(TreeNode* cur,vector<int> &vec)
{
    if(cur == nullptr) return;
    zhongxu(cur->left,vec);
    vec.push_back(cur->val);
    zhongxu(cur->right,vec);

}


// 后序遍历
void houxu(TreeNode* cur,vector<int> &vec)
{
    if(cur == nullptr) return;
    houxu(cur->left,vec);
    houxu(cur->right,vec);
    vec.push_back(cur->val);
}


vector<int> bianli(TreeNode* cur)
{
    vector<int> result;
    qianxu(cur,result);
    return result;
}