#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
/*
当使用STL中的堆容器（如priority_queue）时，堆容器默认使用小顶堆实现。
因此，在定义比较函数时，需要使用大于号而非小于号来实现小顶堆的规则，即使看起来这并不符合人们的直觉。
例如，假设有两个数a和b，
我们希望将较小的数放在较高的位置上，那么在小顶堆中，
应该将a和b进行比较，将较大的数放在较高的位置上。
因此，在比较函数中应该使用大于号而非小于号，以实现我们需要的规则。
*/
class mycompairison
{
    public:
        bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)
        {
            return lhs.second > rhs.second; // 注意小顶堆是大于号
        }
};

vector<int> topKfreq(vector<int> &nums,int k)
{
    unordered_map<int,int> map;
    for(int i = 0;i < nums.size();i++)
    {
        map[nums[i]]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, mycompairison> pri_que;
    /*
    先获取unordered_map容器的开始迭代器，即指向unordered_map中第一个元素的迭代器，
    这里用变量it表示；然后使用for循环，以it为起始迭代器，判断it是否等于unordered_map容器的结束迭代器map.end()，
    即是否仍然存在元素；如果仍然存在元素，则用++运算将it推进到下一个元素，以便下一次迭代使用。
    在每一次迭代中，通过*it获取键值对，即it所指向的元素。假设每个元素都是一对数字，第一个数字是键，第二个数字是值，
    则可以通过it->first和it->second来获取元素的键和值。
    */
    for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) // for (auto it: map)
    {
        pri_que.push(*it); //pri_que.push(it)
        if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
    }
    // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
}