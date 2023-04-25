/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-25 09:58:25
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-25 10:08:18
 * @FilePath: \leetcode\回溯\78子集.cpp
 * @Description: 回溯，与组合的区别是每次都push vec
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> vec;

void dfs(vector<int> &nums,int startIndex)
{
    result.push_back(vec);
    if(startIndex >= nums.size()) return;

    for(int i = startIndex;i < nums.size();i++)
    {
        vec.push_back(nums[i]);
        dfs(nums,i+1);
        vec.pop_back();
    }
}

