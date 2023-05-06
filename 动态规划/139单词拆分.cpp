#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

bool word(string s,vector<string> &wordDick)
{
    unordered_set<string> set(wordDick.begin(),wordDick.end());
    vector<bool> dp(s.size()+1,false);
    dp[0] = true;
    for(int i = 1;i <= s.size();i++)
    {
        for(int j = 0;j < i;j++)
        {
            string tmp = s.substr(j,i-j);
            if(set.find(tmp) != set.end() && dp[j])
            {
                dp[i] = true;
            }
        }
    }

    return dp[s.size()];
}