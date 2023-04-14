#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 数组是最简单的哈希表，其中字母减去'a'
bool yiwei(string s, string t)
{
    vector<int> nums(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        nums[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        nums[t[i] - 'a']--;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool result = yiwei(s, t);
    cout << result << endl;
    return 0;
}