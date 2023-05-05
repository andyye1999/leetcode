/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-05 11:27:45
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-05 16:15:07
 * @FilePath: \leetcode\动态规划\322零钱兑换.cpp
 * @Description: 完全背包 求最小数
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int money(int amount,vector<int> &nums)
{
    vector<int> dp(amount+1,INT32_MAX);
    
    for(int i = 0;i < nums.size();i++)// 遍历物品
    {
        for(int j = nums[i];j <= amount;j++) // 遍历背包
        {
            if(dp[j-nums[i]] != INT32_MAX) // 如果dp[j - coins[i]]是初始值则跳过
            {
                dp[j] = min(dp[j],dp[j-nums[i]] + 1);
            }
        }
    }

    if(dp[amount] == INT32_MAX) return -1;
    return dp[amount];
}