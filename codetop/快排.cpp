#include <iostream>
#include <vector>

using namespace std;


// 快速排序，先移动右指针
void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int x = rand() % (end - start + 1) + start;
    swap(nums[start], nums[x]);
    int firstnum = nums[start];
    int l = start, r = end;
    while (l < r)
    {
        while (l < r && nums[r] >= firstnum)
            --r;
        if (l < r)
        {
            nums[l] = nums[r];
        }
        while (l < r && nums[l] <= firstnum)
            ++l;
        if (l < r)
        {
            nums[r] = nums[l];
        }
    }
    nums[l] = firstnum;
    quickSort(nums, start, l - 1);
    quickSort(nums, l + 1, end);
}

vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size() - 1;
    quickSort(nums, 0, n);
    return nums;
}

int main()
{
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
    vector<int> result = sortArray(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}