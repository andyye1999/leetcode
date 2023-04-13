#include <iostream>
#include <vector>

using namespace std;


// 边界没想到 确定圈数
vector<vector<int>> juzhen(int n)
{
    int quan = n / 2;
    int kong = 1;
    int x = 0;
    int y = 0;
    int i, j;
    int count = 1;
    vector<vector<int>> result(n, vector<int>(n, 0));
    while (quan > 0)
    {
        i = x;
        j = y;
        for (; j < n - kong; j++)
        {
            result[i][j] = count;
            count++;
        }
        for (i = x; i < n - kong; i++)
        {
            result[i][j] = count++;
        }
        for (; j > y; j--)
        {
            result[i][j] = count++;
        }
        for (; i > x; i--)
        {
            result[i][j] = count++;
        }
        x++;
        y++;
        quan--;
        kong++;
    }
    if (n % 2 == 1)
    {
        int mid = n / 2;
        result[mid][mid] = n * n;
    }
    return result;
}

