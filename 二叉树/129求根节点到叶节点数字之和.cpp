/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-23 16:40:18
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-23 16:51:59
 * @FilePath: \leetcode\二叉树\129求根节点到叶节点数字之和.cpp
 * @Description: 
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int result = 0;
void dfs(TreeNode* root,int sum)
{
    sum = sum*10 + root->val;
    if(root->left == nullptr && root->right == nullptr) result += sum;
    if(root->left != nullptr) dfs(root->left,sum);
    if(root->right != nullptr) dfs(root->right,sum);
}

int sumNumber(TreeNode* root)
{
    dfs(root,0);
    return result;
}