#include <iostream>
#include <vector>

using namespace std;

// 快慢指针
int del(vector<int> &nums, int target)
{
    int low = 0;
    for (int fast = 0; fast < nums.size(); fast++)
    {
        if(nums[fast] != target)
        {
            nums[low] = nums[fast];
            low++;
        }
    }
    return low;
}

int main()
{
    vector<int> nums;
    int n;
    while(cin >> n)
    {
        nums.push_back(n);
        if(getchar() == '\n')
        {
            break;
        }
    }
    int result,target;
    cin >> target;
    result = del(nums,target);
    cout << result << endl;
    for(int i = 0;i < result;i++)
    {
        cout << nums[i] << ' ' ;
    }
    return 0;   
}