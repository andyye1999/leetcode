#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 自己创建单调队列，头文件deque
class Myqueue
{
    public:
        deque<int> que;
        void push(int x)
        {
            while(!que.empty() && x > que.back())
            {
                que.pop_back();
            }
            que.push_back(x);
        }

        void pop(int x)
        {
            if(!que.empty() && x == que.front())
            {
                que.pop_front();
            }
        }

        int front()
        {
            return que.front();
        }
};

vector<int> huadong(vector<int> &nums,int target)
{
    Myqueue que;
    vector<int> result;
    for(int i = 0;i < target;i++)
    {
        que.push(nums[i]);
    }
    result.push_back(que.front());
    for(int i = target;i < nums.size();i++)
    {
        que.pop(nums[i-target]);
        que.push(nums[i]);
        result.push_back(que.front());
    }
    return result;
}

int main()
{
    int target;
    cin >> target;
    int n;
    vector<int> nums;
    while (cin >> n)
    {
        nums.push_back(n);
        if(getchar() == '\n')
        {
            break;
        }
    }
    vector<int> result = huadong(nums,target);
    for(int i = 0;i < result.size();i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
    
}