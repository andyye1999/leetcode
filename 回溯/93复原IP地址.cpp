/*
 * @Author: yehongcen && as_yhc@163.com
 * @Date: 2023-04-24 22:02:22
 * @LastEditors: redust as_yhc@163.com
 * @LastEditTime: 2023-04-24 22:34:38
 * @FilePath: \leetcode\回溯\93复原IP地址.cpp
 * @Description: 挺难的
 * Copyright (c) 2023 by yehongcen, All Rights Reserved. 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(const string &s, int start, int end)
{
    if (start > end)
    {
        return false;
    }
    if (s[start] == '0' && start != end)
        return false;
    int num = 0;
    for (int i = start; i <= end; i++)
    {
        if (s[i] > '9' || s[i] < '0')
            return false;
        num = num * 10 + (s[i] - '0');
        if (num > 255)
            return false;
    }
    return true;
}

vector<string> result;
void dfs(string &s, int startIndex, int point)
{
    if (point == 3)
    {
        if (isValid(s, startIndex, s.size() - 1))
        {
            result.push_back(s);
        }
        return;
    }

    for (int i = startIndex; i < s.size(); i++)
    {
        if (isValid(s, startIndex, i))
        {
            s.insert(s.begin() + i + 1, '.');
            point++;
            dfs(s, i + 2, point);
            point--;
            s.erase(s.begin() + i + 1);
        }
        else
            break;
    }
}

vector<string> IP(string s)
{
    dfs(s, 0, 0);
    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result;
    result = IP(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}