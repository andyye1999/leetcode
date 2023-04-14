#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// unordered_map 头文件 find insert(pair<int,int>)
vector<int> twosum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        auto tmp = map.find(target - nums[i]);
        if (tmp != map.end())
        {
            result.push_back(tmp->second);
            result.push_back(i);
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return result;
}

int main()
{
    int target;
    cin >> target;
    int n;
    vector<int> nums, result;
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    result = twosum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}