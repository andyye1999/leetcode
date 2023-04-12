#include <iostream>
#include <vector>

using namespace std;


// 双指针，不过存储时是从右到左一直动的
vector<int> mypow(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int t = nums.size() - 1;
    vector<int> result(nums.size(), 0);
    while (left <= right)
    {
        if ((nums[left] * nums[left]) < (nums[right] * nums[right]))
        {
            result[t] = nums[right] * nums[right];
            right--;
            t--;
        }
        else
        {
            result[t] = nums[left] * nums[left];
            left++;
            t--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums;
    vector<int> result;
    int n;
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    result = mypow(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}