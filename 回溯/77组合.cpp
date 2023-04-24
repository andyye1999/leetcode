/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-24 13:00:03
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-24 14:20:52
 * @FilePath: \leetcode\回溯\77组合.cpp
 * @Description: 
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> vec;

void dfs(int n, int k, int target)
{
    if (vec.size() == k) // 这个if没想出来
    {
        result.push_back(vec);
        return;
    }

    for (int i = target; i <= n; i++)
    {
        vec.push_back(i);
        dfs(n, k, i + 1); // 是i+1
        vec.pop_back();
    }
}

vector<vector<int>> zuhe(int n, int k)
{
    dfs(n, k, 1);
    return result;
}