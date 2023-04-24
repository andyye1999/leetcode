/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-24 14:19:50
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-24 14:23:16
 * @FilePath: \leetcode\回溯\39组合总和.cpp
 * @Description: 回溯
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int startIndex)
    {
        int sum = 0;
        for (int i = 0; i < path.size(); i++)
        {
            sum += path[i];
        }
        if (sum > target)
            return; // 没写这个没通过
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {

            path.push_back(candidates[i]);
            backtracking(candidates, target, i); // 不用i+1了，表示可以重复读取当前的数
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};