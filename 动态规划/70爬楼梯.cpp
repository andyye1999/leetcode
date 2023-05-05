/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-26 23:00:31
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-26 23:13:44
 * @FilePath: \leetcode\动态规划\70爬楼梯.cpp
 * @Description: dp dp[i] = dp[i-1] + dp[i-2]; 当前楼梯等于上一层楼梯加上两层楼梯
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

int climb(int n)
{
    if(n <= 1) return n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < n + 1;i++) // i=3  注意！
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int result = climb(n);
    cout << result << endl;
    return 0;
}
