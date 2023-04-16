#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {}
    void push(int x)
    {
        stIn.push(x);
    }
    int pop()
    {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top()); // 注意顺序
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek()
    {
        int result = this->pop(); // 复用
        stOut.push(result);
        return result;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};