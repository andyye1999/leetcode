#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 先排序，双指针法，再去重 头文件<algorithm>
vector<vector<int>> threesum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(),nums.end()); // 头文件<algorithm>
    for(int i = 0;i < nums.size();i++)
    {
        if(nums[i] > 0 ) return result;
        int left = i + 1;
        int right = nums.size()-1;
        if(i > 0 && nums[i] == nums[i-1]) continue; // i>0 没写报错
        while(left < right)
        {
            if(nums[i] + nums[left] + nums[right] > 0) right--;
            else if(nums[i] + nums[left] + nums[right] < 0) left++;
            else
            {
                result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                while(left < right && nums[right] == nums[right - 1]) right--;
                while(left < right && nums[left] == nums[left + 1]) left++;
                left++;
                right--;
            }
        }
    }
    return result;
}