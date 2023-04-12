#include <iostream>
#include <vector>

using namespace std;

// 滑动窗口想到了，但这个for循环和while循环结合以及sum减没想出来
int lengthsum(vector<int> &nums, int target)
{
    int left = 0;
    int right = 0;
    int result = INT32_MAX;
    int sum = 0;
    int len;
    for (right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            len = right - left + 1;
            sum -= nums[left];
            left++;
            result = result < len ? result : len;
        }
    }
    result = result == INT32_MAX ? 0 : result;
    return result;
}

int main()
{
    vector<int> nums;
    int n;
    int target;
    cin >> target;
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    int result;
    result = lengthsum(nums, target);
    cout << result << endl;
    return 0;
}