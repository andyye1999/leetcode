/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-06 14:58:55
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-06 15:11:48
 * @FilePath: \leetcode\动态规划\718最长重复子数组.cpp
 * @Description: dp[i][j]代表以A[i-1]与B[j-1]结尾的公共字串的长度,公共字串必须以A[i-1]，B[j-1]结束，即当A[i-1] == B[j-1]时，dp[i][j] = dp[i-1][j-1] + 1;   
    当A[i-1] != B[j-1]时，以A[i-1]和B[j-1]结尾的公共字串长度为0,dp[i][j] = 0。  
    输出最大的公共字串的长度即为最长重复字串。
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2)
{
    vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
    int result = 0;
    for(int i = 1;i <= nums1.size();i++)
    {
        for(int j = 1;j <= nums2.size();j++)
        {
            if(nums1[i-1] == nums2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        if(dp[i][j] > result) result = dp[i][j];
        }
    } 
    return result;
}