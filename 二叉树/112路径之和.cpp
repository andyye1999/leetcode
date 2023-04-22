/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-20 20:59:46
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-22 14:50:02
 * @FilePath: \leetcode\二叉树\112路径之和.cpp
 * @Description: 路径之和
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
 * @description: 递归
 * @param {TreeNode} *root
 * @param {int} sum
 * @return {*}
 */
bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;
    if (!root->left && !root->right && sum == root->val)
    {
        return true;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}



/**
 * @description: 迭代法
 * @param {TreeNode} *root
 * @param {int} sum
 * @return {*}
 */
bool diedai(TreeNode *root, int sum)
{
    if (root == nullptr)
        return false;
    // 此时栈里要放的是pair<节点指针，路径数值>
    stack<pair<TreeNode *, int>> st;
    st.push(pair<TreeNode *, int>(root, root->val));
    while (!st.empty())
    {
        pair<TreeNode *, int> node = st.top();
        st.pop();
        // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
        if (!node.first->left && !node.first->right && sum == node.second)
            return true;

        // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if (node.first->right)
        {
            st.push(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
        }

        // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if (node.first->left)
        {
            st.push(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));
        }
    }
    return false;
}