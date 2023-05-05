/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-05 10:56:11
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-05 11:05:09
 * @FilePath: \leetcode\动态规划\518零钱兑换2.cpp
 * @Description: 完全背包组合 模板 第二层循环变成正序 然后dp是累加
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int money(int count,vector<int> &nums)
{
    vector<int> dp(count + 1, 0);
    dp[0] = 1;
    for(int i = 0;i < nums.size();i++)
    {
        for(int j = nums[i];j <= count;j++) // 完全背包 组合 变成正序
        {
            dp[j] += dp[j-nums[i]]; // 组合的模板
        }
    }
    return dp[count];
}

int main()
{
    int count;
    cin >> count;
    int n;
    vector<int> nums;
    while(cin >> n)
    {
        nums.push_back(n);
        if(getchar() == '\n')
        {
            break;
        }
    }
    int result = money(count,nums);
    cout << result << endl;
    return 0;
}