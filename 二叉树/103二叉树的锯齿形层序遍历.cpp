/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-23 13:18:19
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-23 13:26:01
 * @FilePath: \leetcode\二叉树\103二叉树的锯齿形层序遍历.cpp
 * @Description: 
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <queue>
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
 * @description: 在指定行反转数组
 * @param {TreeNode} *root
 * @return {*}
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    queue<TreeNode *> que;
    bool target = false;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            vec[target ? size - 1 - i : i] = node->val;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        result.push_back(vec);
        target = !target;
    }
    return result;
}