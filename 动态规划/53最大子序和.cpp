/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-06 17:15:41
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-06 17:19:03
 * @FilePath: \leetcode\动态规划\53最大子序和.cpp
 * @Description: dp[i]只有两个方向可以推出来：
    dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
    nums[i]，即：从头开始计算当前连续子序列和
    一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);  
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    int result = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}