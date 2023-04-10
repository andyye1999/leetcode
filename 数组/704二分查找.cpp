#include <iostream>
#include <vector>

using namespace std;
class solusion
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{

    solusion twosearch;
    int n;
    vector<int> nums;
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    int target;
    cin >> target;
    int result;
    result = twosearch.search(nums, target);
    cout << result << endl;
    return 0;
}