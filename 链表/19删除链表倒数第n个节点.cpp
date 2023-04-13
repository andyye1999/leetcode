#include <iostream>

using namespace std;


//写对了，在虚拟头节点上操作
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* shanchu(ListNode* head,int n)
{
    ListNode* virhead = new ListNode(0);
    virhead->next = head;
    ListNode* slow = virhead;
    ListNode* fast = virhead;
    for(int i = 0;i < n;i++)
    {
        fast = fast->next;
    }
    while(fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    ListNode* result = virhead->next;
    return result;
}

int main()
{
    ListNode* LHead = new ListNode(0);
    ListNode* pre = LHead;
    ListNode* cur = nullptr;
    int num;
    cin >> num;
    int n;
    while(cin >> n)
    {
        cur = new ListNode(n);
        pre->next = cur;
        pre = cur;
        if(getchar() == '\n')
        {
            break;
        }
    }
    cur = LHead->next;
    ListNode* result;
    result = shanchu(cur,num);
    while(result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}