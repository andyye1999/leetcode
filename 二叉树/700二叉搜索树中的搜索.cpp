/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-22 16:13:25
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-22 16:21:38
 * @FilePath: \leetcode\二叉树\700二叉搜索树中的搜索.cpp
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

TreeNode* searchTree(TreeNode* root,int target)
{
    if(root == nullptr || root->val == target) return root;
    TreeNode* result;
    if(root->val > target) result = searchTree(root->left,target);
    if(root->val < target) result = searchTree(root->right,target);
    return result;
}