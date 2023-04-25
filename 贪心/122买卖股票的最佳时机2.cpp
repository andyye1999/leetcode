/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-25 21:51:16
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-25 21:52:04
 * @FilePath: \leetcode\贪心\122买卖股票的最佳时机2.cpp
 * @Description: 贪心，找每天的差值并相加
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int> &prices)
{
    vector<int> result(prices.size() - 1);
    for (int i = 1; i < prices.size(); i++)
    {
        result[i - 1] = prices[i] - prices[i - 1];
    }
    int sum = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] > 0)
            sum += result[i];
    }
    return sum;
}