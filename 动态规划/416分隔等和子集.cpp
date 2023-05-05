/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-04 19:22:43
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-05 10:55:31
 * @FilePath: \leetcode\动态规划\416分隔等和子集.cpp
 * @Description: 01背包相对于本题，主要要理解，题目中物品是nums[i]，重量是nums[i]，价值也是nums[i]，背包体积是sum/2。
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canPartition(vector<int> &nums)
{
    // int sum = 0;
    vector<int> dp(10001,0);
    // 也可以使用库函数一步求和 头文件#include <numeric>
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % 2 == 1) return false;
    int target = sum / 2;

    // 01背包
    for(int i = 0;i < nums.size();i++)
    {
        for(int j = target;j >= nums[i];j--) // 01背包 第二层背包循环是倒序
        {
            dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
        }
    }

    if(dp[target] == target) return true;
    return false;
}