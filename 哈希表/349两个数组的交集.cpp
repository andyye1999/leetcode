#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


// unordered_set 头文件 begin end find insert
vector<int> jiaoji(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> result;
    unordered_set<int> tmp(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        if (tmp.find(num) != tmp.end())
        {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}

int main()
{
    int n;
    vector<int> nums1, nums2;
    while (cin >> n)
    {
        nums1.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    while (cin >> n)
    {
        nums2.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    vector<int> result = jiaoji(nums1, nums2);
    for (int num : result)
    {
        cout << num << ' ';
    }
    return 0;
}