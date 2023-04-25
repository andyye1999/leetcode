/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-25 17:35:13
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-25 19:13:28
 * @FilePath: \leetcode\回溯\46全排列.cpp
 * @Description: 排列模板，不用startindex，有used数组
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> result;
vector<int> path;
void dfs(vector<int> &nums,vector<bool> &used)
{
    if(path.size() == nums.size())
    {
        result.push_back(path);
        return;
    }

    for(int i = 0;i < nums.size();i++) // i从0开始，不用startIndex了
    {
        if(used[i] == true) continue; // path里已经收录的元素，直接跳过
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums,used);
        used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> quanpailie(vector<int> &nums)
{
    vector<bool> used(nums.size(),false);
    dfs(nums,used);
    return result;
}