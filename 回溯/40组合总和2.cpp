/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-25 11:31:38
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-25 11:32:52
 * @FilePath: \leetcode\回溯\40组合总和2.cpp
 * @Description: 考察回溯如何去重
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++)
        {
            sum += path[i];
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};