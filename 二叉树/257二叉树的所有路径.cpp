#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


// 回溯，还是不太懂
void traversal(TreeNode* cur,vector<int> &path,vector<string> &result)
{
    path.push_back(cur->val);
    if(cur->left == nullptr && cur->right == nullptr)
    {
        string s;
        for(int i = 0;i < path.size()-1;i++)
        {
            s += to_string(path[i]);
            s += '->';
        }
        s += to_string(path[path.size()-1]);
        result.push_back(s);
        return;
    }

    if(cur->left)
    {
        traversal(cur->left,path,result);
        path.pop_back(); // 回溯
    }

    if(cur->right)
    {
        traversal(cur->right,path,result);
        path.pop_back();
    }

}

vector<string> suoyoulujing(TreeNode* root)
{
    vector<int> path;
    vector<string> result;
    if(root == nullptr) return result;
    traversal(root,path,result);
    return result;
}