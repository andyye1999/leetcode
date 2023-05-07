#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int len = 0;
    int left = 0;
    int right = 0;
    for (int i = s.size() - 1; i >= 0; i--) // 注意是--
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1) // 分情况
                {
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
            if (dp[i][j] && j - i + 1 > len)
            {
                len = j - i + 1;
                left = i;
                right = j;
            }
        }
    }

    return s.substr(left, len);
}