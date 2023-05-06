/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-06 13:58:44
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-06 14:06:38
 * @FilePath: \leetcode\动态规划\300最长上升子序列.cpp
 * @Description: 位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    if(len <= 1) return len;
    vector<int> dp(len,1); // 1 不是0
    int result = 0;
    for(int i = 1;i < len;i++)
    {
        for(int j = 0;j < i;j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[j]+1,dp[i]); // 位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
            }
        }
        if(result < dp[i]) result = dp[i]; // 取长的子序列
    }
    return result; 
}