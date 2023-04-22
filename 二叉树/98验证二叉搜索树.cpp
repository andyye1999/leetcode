/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-22 16:27:19
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-22 21:56:47
 * @FilePath: \leetcode\二叉树\98验证二叉搜索树.cpp
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

// 不能只判断左节点小于中间节点，右节点大于中间节点

vector<int> vec;
/**
 * @description: zhongxupaixu
 * @param {TreeNode*} root
 * @return {*}
 */
void zhongxu(TreeNode* root)
{
    if(root == nullptr) return ;
    zhongxu(root->left);
    vec.push_back(root->val);
    zhongxu(root->right);
}

/**
 * @description: 看vec顺序判断
 * @param {TreeNode*} root
 * @return {*}
 */
bool isBST(TreeNode* root)
{
    zhongxu(root);
    for(int i = 1;i <vec.size();i++)
    {
        if(vec[i-1] > vec[i]) return false;
    }
    return true;
}
