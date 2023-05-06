/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-06 13:35:45
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-06 14:01:00
 * @FilePath: \leetcode\动态规划\121买卖股票.cpp
 * @Description: 股票模板
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int money(vector<int> &nums)
{
    int len = nums.size();
    if(len == 0) return 0;
    vector<vector<int>> dp(len,vector<int>(2));
    dp[0][0] -= nums[0];
    dp[0][1] = 0;
    for(int i = 1;i < len;i++)
    {
        dp[i][0] = max(dp[i-1][0],-nums[i]); // 持有股票
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+nums[i]); // 不持有股票
    }
    return dp[len-1][1];
}