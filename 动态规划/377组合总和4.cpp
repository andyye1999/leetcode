/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-05-05 11:21:56
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-05-05 11:26:28
 * @FilePath: \leetcode\动态规划\377组合总和4.cpp
 * @Description: 完全背包 排列模板 背包和物品换序 而且有个if
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT32_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};