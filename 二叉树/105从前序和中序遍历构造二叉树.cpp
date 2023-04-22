/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-22 15:16:44
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-22 16:12:05
 * @FilePath: \leetcode\二叉树\105从前序和中序遍历构造二叉树.cpp
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


/**
 * @description: 前序最左边是根节点，在中序中找根节点，中序左边和右边
 * @param {int} leftqian
 * @param {int} rightqian
 * @param {int} leftzhong
 * @param {int} rightzhong
 * @param {vector<int>} &qian
 * @param {vector<int>} &zhong
 * @return {*}
 */
TreeNode* digui(int leftqian,int rightqian,int leftzhong,int rightzhong,vector<int> &qian,vector<int> &zhong)
{
    if(leftqian > rightqian || leftzhong > rightzhong) return nullptr;
    TreeNode* node = new TreeNode(qian[leftqian]);
    int root = leftzhong;
    while (root <= rightzhong && zhong[root] != qian[leftqian])
    {
        /* code */
        root++;
    }
    int left = root - leftzhong;
    node->left = digui(leftqian+1,leftqian+left,leftzhong,root-1,qian,zhong);
    node->right = digui(leftqian+left+1,rightqian,root+1,rightzhong,qian,zhong);
    return node;
    
}

TreeNode* buildTree(vector<int> qian,vector<int> zhong)
{
    TreeNode* result;
    result = digui(0,qian.size()-1,0,zhong.size()-1,qian,zhong);
    return result;
}
