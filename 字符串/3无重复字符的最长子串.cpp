#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int len = 0;
    unordered_set<char> set;
    for (int i = 0; i < s.size(); i++)
    {
        while (set.find(s[i]) != set.end())
        {
            set.erase(s[left]); // 全部移除
            left++;
        }
        set.insert(s[i]);
        if (i - left + 1 > len)
            len = i - left + 1;
    }
    return len;
}