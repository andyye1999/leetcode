/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-06 16:19:17
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-06 16:27:51
 * @FilePath: \leetcode\动态规划\1143最长公共子序列.cpp
 * @Description: dp[i][j] 表示text1[0~i-1]和text2[0~j-1]的最长公共子序列长度 dp[0][0]等于0，   
    等于dp数组总体往后挪了一个，免去了判断出界 转移方程： text1[i-1] == text2[j-1]   
    当前位置匹配上了: dp[i][j]=dp[i-1][j-1]+1 text1[i-1] ！= text2[j-1] 当前位置没匹配上了 ：dp[i][j]=max(dp[i-1][j],dp[i][j-1]);   
    basecase: 任何一个字符串为0时都是零，初始化时候就完成了basecase是赋值
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}