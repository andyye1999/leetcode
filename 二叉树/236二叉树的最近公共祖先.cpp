/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-22 22:50:02
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-22 23:12:32
 * @FilePath: \leetcode\二叉树\236二叉树的最近公共祖先.cpp
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
 * @description: 自底向上 后序遍历是自底向上 回溯
 * @param {TreeNode*} root
 * @param {TreeNode*} p
 * @param {TreeNode*} q
 * @return {*}
 */
TreeNode* zuxian(TreeNode* root,TreeNode* p,TreeNode* q)
{
    //公司技术部出了两个叛徒，技术部的每个小部门都有两个部门（二叉树）要找出他们的Line Manager
    //各单位开始排查，从基层员工查起，最后汇总，找第一个Line manager
    
    if(root == nullptr) return root;
    //我自己是叛徒之一，但是我不一定受到惩罚，因为要找的是叛徒的老板，但是你代表你的团队找到了一个叛徒
    if(root == p || root == q) return root;
    //在各层级团队找叛徒
    TreeNode * left = zuxian(root->left,p,q);
    //在各层级团队找叛徒
    TreeNode* right = zuxian(root->right,p,q);
    //我们团队找到两叛徒了，game over,倒霉的就是我。接下去我会被一层一层的往上提交，最后到老板那。
    if(left != nullptr && right != nullptr) return root;
    //我们团队只找到一个叛徒，这个叛徒代表整个团队，就用这个叛徒来向上（回溯）提交甩锅
    if(left == nullptr && right != nullptr) return right;
    if(left != nullptr && right == nullptr) return left;
    return nullptr;  //我们是最干净的团队！
}